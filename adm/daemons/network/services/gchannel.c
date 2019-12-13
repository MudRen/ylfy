/*
 * This protocol is used to broadcast a channel to a group of other muds.
 */

// by Annihilator (06/15/95)

#undef DEBUG

#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/services.h>
#include <net/gchannel.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
string *big5_mud_list=BIG5_MUD_IP;
void create() {
	seteuid(ROOT_UID);
	set("channel_id", "��·Ƶ������");
 }

// This is the interface to the intermud channels
void send_msg(string channel, string id, string name, string msg, int emoted,
	mixed filter)
{
	string *names;
	int i;
	mapping muds;
	mapping svcs;
	mapping minfo;

//	if( !this_player()		// Prevent from being called by ourself.
//	||	!ACCESS_CHECK(previous_object())) return;
	if( !ACCESS_CHECK(previous_object())) return;

#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(), DEBUG, "prepare to send gchannel message.");
#endif
	muds = (mapping)DNS_MASTER->query_muds();
	svcs = (mapping)DNS_MASTER->query_svc();
	msg = replace_string(msg, "|", "");
	msg = replace_string(msg, "@@@", "");
	// use keys(svcs) because none of the muds not in svcs can possibley
	// receive the message
	names = keys(svcs);
	i = sizeof(names);
	while(i--)
		if( (names[i] != mud_nname())
		&&	evaluate(filter, muds[names[i]])) {
			minfo = muds[names[i]];
			if(!mapp(minfo) || !mapp(svcs[names[i]])
			|| !(svcs[names[i]]["gwizmsg"] & SVC_UDP))
				continue;
//                if( channel !="gwiz" && minfo["MUDLIB"] != "Eastern Stories" && minfo["MUDLIB"] != "A Journey to the West" )
//                        continue;

		DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
				"@@@" + DNS_GCHANNEL +
				"||NAME:" + Mud_name() +
				"||PORTUDP:" + udp_port() +
				"||USRNAME:" + capitalize(id) +
				"||CNAME:" + name  +
				"||MSG:" + msg  +
				"||CHANNEL:" + channel +
				(emoted?"||EMOTE:1":"") + "@@@\n");
	}
}

void incoming_request(mapping info)
{
	mapping minfo;
        string tmsg;

#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(), DEBUG,
		sprintf("gchannel message get from %s:%s.", info["HOSTADDRESS"],info["PORTUDP"]));
#endif
	if(!ACCESS_CHECK(previous_object())) return;
	if (info["NAME"]) {
		if (info["NAME"] == Mud_name()) return ;

		minfo = DNS_MASTER->query_mud_info(info["NAME"]);
		if (!minfo || !strlen(info["USRNAME"])
		|| !DNS_MASTER->dns_mudp(info["NAME"]))	{
			// We don't accept the message.  But ping them anyway.
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
			return ;
		}
		if ( (info["HOSTADDRESS"] != minfo["HOSTADDRESS"]) ) {

			if (info["EMOTE"])
                                tmsg = info["USRNAME"]+"@"+upper_case(info["NAME"])+" "+info["MSG"];
			else
				tmsg = info["USRNAME"]+"@"+info["NAME"]+": "+info["MSG"];

			// Faked.  sheeze... 
			dns_log("dns_fake",sprintf( "Gchannel: %s %s\n%s", ctime(time()),
				info["HOSTADDRESS"],tmsg));
			DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
				"@@@"+DNS_WARNING+
				"||NAME:"+Mud_name()+
				"||MSG: Fake gchannel msg: "+tmsg+
				"||FAKEHOST:"+info["HOSTADDRESS"]+
				"@@@\n");
			return;
		}

		if( undefinedp(info["CNAME"]) )
			set("channel_id", sprintf("%s@%s", info["USRNAME"], info["NAME"]) );
		else
			set("channel_id",  sprintf("%s(%s@%s)",info["CNAME"], info["USRNAME"], info["NAME"]) );
		//�ж����벢ת������
               if( (!undefinedp(minfo["ENCODING"]) && lower_case(minfo["ENCODING"])=="big5")
		   || (!undefinedp(info["ENCODING"]) && info["ENCODING"]=="BIG5")
		   || member_array(info["HOSTADDRESS"],big5_mud_list)!=-1
		) {
			info["MSG"]=LANGUAGE_D->toGB(info["MSG"])+"[BIG5��]";
			set("channel_id",LANGUAGE_D->toGB(query("channel_id")));
		}
			info["MSG"] = replace_string(info["MSG"],"[2J","");
		CHANNEL_D->do_channel(this_object(), lower_case(info["CHANNEL"]), info["MSG"], info["EMOTE"], 1);
    } //if (info["NAME"])
}

