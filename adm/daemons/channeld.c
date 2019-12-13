// channeld.c 
// 97-10-18 add intermud channel and emote capability
//      By ken@XAJH & fuyo@XAJH 
//Tomud协议：小窗口信息标识"small_window" 

#include <ansi.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>
#include <liebiao.h>

inherit F_DBASE;

#define BLOCK_CHAT      0
#define BLOCK_RUMOR     0
#define REMOTE_Q        "/adm/daemons/network/services/remote_q.c"

string remove_addresses(string, int all);

mapping channels = ([
	
	"sys":  ([  "msg_speak": HIR "【系统通告】%s：%s\n" NOR,
	            "msg_color": NOR+WHT,
			    "wiz_only": 1,
				//"small_window":1,
			]),
	
	"adm":  ([  "msg_speak": HIW "%s: %s\n" NOR,
			    "msg_emote": NOR+HIW+"【天神】%s" NOR,
			    "msg_color": NOR+HIW,
			    "arch_only": 1,
				"small_window":1,
			]),
	
	"admin":([  "msg_speak": HIR "%s: %s\n" NOR,
                "msg_emote": NOR+HIR+"〖天帝〗%s" NOR,
                "msg_color": NOR+HIW,
                "adm_only": 1,
				"small_window":1,
			]),
	
	"wiz":  ([  "msg_speak": NOR+HIY+"【巫师】"+HIG+"%s：%s\n" NOR,
                "msg_emote": NOR+HIY+"【巫师】"+HIG+"%s" NOR,
                "msg_color": NOR+HIY,           
                "wiz_only": 1,
                "intermud": GCHANNEL,
                "intermud_emote": 1, 
                "channel": "wiz",
                "omit_address": 0,
				"small_window":1,
            ]),

    "gwiz": ([  "msg_speak": NOR+HIC+"【网际巫师】"+HIY+"%s：%s\n" NOR,
                "msg_emote": NOR+HIC+"【网际巫师】"+HIY+"%s" NOR,
                "wiz_only": 1,
                "intermud": GCHANNEL,
                "intermud_emote": 1,
                "channel": "gwiz",
                "msg_color": NOR+HIY,
                "filter": 1,
                "omit_address": 0, 
				"small_window":1,
            ]),

    "gbwiz":([  "msg_speak": BOLD "【大陆巫师】%s：%s\n" NOR,
                "msg_emote": BOLD "【大陆巫师】%s" NOR,
                "msg_color": BOLD,
                "intermud": GCHANNEL,
                "intermud_emote": 1, 
				"small_window":1,
                "channel": "gbwiz",
                "omit_address": 0,
                "wiz_only": 1,
                "filter": (: $1["ENCODING"] == MUDLIB_ENCODING :)
            ]),

    "debug":([  "msg_speak": HIW "【调试报告】%s：%s\n" NOR,
                "msg_emote": HIY "【调试报告】%s" NOR,
                "wiz_only": 1,
            ]),
	
	"chat": ([  "msg_speak": HIC+"〖"+HIY"茶余饭后"NOR+HIC"〗%s：%s\n" NOR,
                "msg_emote": HIC+"〖"+HIY"茶余饭后"NOR+HIC"〗"+"%s" NOR,
                "msg_color": NOR+HIC,
				"small_window":1,
            
            ]),
	
	"new":  ([  "msg_speak": HIC+"【"+HIG+"初来乍到"+HIC+"】%s：%s\n" NOR,
                "msg_emote": HIC+"【"+HIG+"初来乍到"+HIC+"】"+HIC+"%s" NOR,	
                "small_window":1,
                "msg_color": NOR+HIC,
            ]),
	
	"xyxw": ([  "msg_speak": HIY+"【"+BRED+HIG+"信息通告"NOR+HIY+"】"BRED+HIY+"%s：%s\n" NOR,	
                "msg_emote": HIY+"【"+BRED+HIG+"信息通告"NOR+HIY+"】"+BRED+HIY+"%s" NOR,	
                "small_window":1,
                "msg_color": NOR+HIC,
			]),
	
	"jypm": ([  "msg_speak": HIG+"【"+HIM+"拍卖现场"+HIG+"】"+HIW+"%s%s\n" NOR,
	            "msg_emote": HIG+"【"+HIM+"拍卖现场"+HIG+"】"+HIW+"%s" NOR,
				"small_window":1,
				"msg_color": NOR+HIC,
			]),
	
	"rumor":([  "msg_speak": HIR "【谣言四起】%s：%s\n" NOR,
	            "msg_emote": HIR "【谣言四起】%s" NOR,
				"small_window":1,
				"msg_color": NOR+HIM,
				"anonymous": "某人",
			]),
	
	"shout":([  "msg_speak": HIY "【%s】%s: %s\n" NOR,
	            "msg_emote": YEL "【%s】%s" NOR,
				"msg_color": NOR+YEL,
			]),
			
	"es":   ([  "msg_speak": NOR+HIC+"〖"HIW+HBMAG"网际传情"NOR+HIC"〗"+BRED+HIW+"%s：%s\n" NOR,
	            "msg_emote": NOR+HIG+"〖"HIW+HBMAG"网际传情"NOR+HIG"〗"+BBLU+HIW+"%s" NOR,
				"msg_color": NOR+BOLD,
				"intermud": GCHANNEL,
				"intermud_emote": 1,
				"small_window":1,
				"channel": "es",
				"filter": 1,
				"omit_address": 0,
			]),
	
	"jh":   ([  "msg_speak": HIG "【"+HIR"夕阳再现"NOR+HIG"】"+NOR+HIG+"%s：%s\n" NOR,
	            "msg_emote": HIG "【"+HIR"夕阳再现"NOR+HIG"】"+NOR+HIG+"%s" NOR,
				"small_window":1,
				"msg_color": NOR+HIG,
				"filter": 1,
				"omit_address": 0,
			]),
	
	"xy":   ([  "msg_speak": HIB "【"+HIW"会员互动"NOR+HIB"】"+NOR+HIM+"%s：%s\n" NOR,
	            "msg_emote": HIB "【"+HIW"会员互动"NOR+HIB"】"+NOR+YEL+"%s" NOR,
				"small_window":1,
				"msg_color": NOR+HIG,
				"filter": 1,
				"omit_address": 0,
			]),
]);

void create()
{
    // This is required to pass intermud access check.
    seteuid(getuid());
    set("channel_id", "频道精灵");
}

varargs int do_channel(object me, string verb, string arg, int emote,int remote)
{
    object *ob_zmud,*ob_tomud;
    string *tuned_ch, who;
    string arg_bk,self_emote,last_arg;
    self_emote=arg;

    // Check if this is a channel emote.
    if( sizeof(verb) > 2 ) {
        if( verb[sizeof(verb)-1] == '*' ) {
            emote = 1;
            verb = verb[0..<2];
            }
    }
     if(arg && strlen(arg)>350) {
CHANNEL_D->do_channel(this_object(),"sys",me->query("name")+"("+me->query("id")+")企图Flood毁坏公共频道！\n");
     return 1;
     }
    // Check if this is a channel messsage.
    if( !mapp(channels) || undefinedp(channels[verb]) ) return 0;

    // check if this channel support emote message. 
    if( emote && undefinedp(channels[verb]["msg_emote"])  ) {
        write("对不起，这个频道不支持 emote 。\n");
        return 1;
    }
    //now we can be sure it's indeed a channel message:
    if (!stringp(arg) || arg == "" || arg == " ") arg = "...";
    else arg_bk = arg;
    
    if(remote) arg_bk = arg;

    // check if one can write to channels
    // only block rumor or chat...
        if ( userp(me) && !wizardp(me)){
         if (mapp(me->query("chblk_channel")))
         me->delete("chblk_channel");
      if (time() - (int)me->query("chblk_channel") < 3600)
                        return notify_fail("你的公共频道被关闭了！\n");
         if (time() - (int)me->query("chblk_rumor") < 3600 && (verb == "rumor"||verb=="rumor*"))
                        return notify_fail("你的谣言频道被关闭了！\n");
          if (time() - (int)me->query("chblk_chat") < 3600 && (verb == "chat"||verb=="chat*"))
                         return notify_fail("你的闲聊频道被关闭了！\n");
           if (time() - (int)me->query("chblk_new") < 3600 && (verb == "new"||verb=="new*"))
                        return notify_fail("你的新手频道被关闭了！\n");
            if (time() - (int)me->query("chblk_es") < 3600 && (verb == "es"||verb=="es*"))
                        return notify_fail("你的网际频道被关闭了！\n");
            if (time() - (int)me->query("chblk_jh") < 3600 && (verb == "jh"||verb=="jh*"))
                          return notify_fail("你的夕阳频道被关闭了！\n");  
			if (time() - (int)me->query("chblk_xy") < 3600 && (verb == "xy"||verb=="xy*"))
                          return notify_fail("你的互动频道被关闭了！\n");  
			if (time() - (int)me->query("chblk_shout") < 3600 && (verb == "shout"||verb=="shout*"))
				return notify_fail("你的交谈频道被关闭了！\n");  
        }

        if( userp(me) ) {
        if( channels[verb]["wiz_only"] && !wizardp(me))
        return 0;
        if( channels[verb]["arch_only"] && wiz_level(me)<wiz_level("(arch)"))
        return 0;
        if( channels[verb]["adm_only"] && wiz_level(me)<wiz_level("(admin)"))
        return 0;
    // check if same channel message but not wizard
    last_arg=(string)me->query_temp("last_channel_msg");
    if( last_arg && !wizardp(me))
//        if( arg==last_arg  || strsrch(last_arg,arg)!=-1 || strsrch(arg,last_arg)!=-1)
        if( userp(me) && arg==last_arg )
    return notify_fail("用交谈频道说话请不要重复相同的讯息。\n");
//   if( !wizardp(me) && (strsrch(arg,"云")!=-1 || strsrch(arg,"梦")!=-1 || strsrch(arg,"嫣")!=-1 || strsrch(arg,"然")!=-1 || strsrch(arg,"妈")!=-1) )       	
/*
if( !wizardp(me) && ((strsrch(arg,"(")!=-1 && strsrch(arg,")")!=-1) || (strsrch(arg,"（")!=-1 && strsrch(arg,"）")!=-1) || (strsrch(arg,"(")!=-1 && strsrch(arg,"）")!=-1) || (strsrch(arg,"（")!=-1 && strsrch(arg,")")!=-1) || strsrch(arg,"妈")!=-1 || strsrch(arg,"奶")!=-1 || strsrch(arg,"娘")!=-1 ))	
{
me->set("chblk_channel",time());
do_channel( this_object(), "rumor", sprintf("悔天鬼王拿出一张狗皮膏药，在小火炉上细细地煨热以后，“啪”地捂住了%s的嘴巴。\n", me->name(1) ));
return 1;
}
*/

    if( userp(me) && !wizardp(me)) {
 
        me->add_temp("channel_msg_cnt", 1);
       if (me->query_temp("channel_msg_cnt")>5)
            if (time()-me->query_temp("chat_time")<2){
/*
                me->set("chblk_channel",time());
                do_channel( this_object(), "rumor", sprintf("悔天鬼王拿出一张狗皮膏药，在小火炉上细细地煨热以后，“啪”地捂住了%s的嘴巴。\n", me->name(1) ));
*/
                return 1;
            }else{
                me->set_temp("chat_time",time());
                me->delete_temp("channel_msg_cnt");
            }
    }

    // If we speaks something in this channel, then must tune it in.
    tuned_ch = me->query("channels");
    if( !pointerp(tuned_ch) )
        me->set("channels", ({ verb }) );
    else if( member_array(verb, tuned_ch)==-1 )
    me->set("channels", tuned_ch + ({ verb }) );
     if ( userp(me) && me->query("age")<18 && verb!="new" && !wizardp(me) && verb!="xy")
          return notify_fail("对不起，18岁前只能用新手(new)频道。\n");
	 if(userp(me) && !me->query("xy_huiyuan") && verb=="xy")
		 return notify_fail("只有会员才能使用互动(xy)频道。\n");
if(userp(me) && me->query_temp("apply/name") && !wizardp(me))   	
return notify_fail("你还是先取下面具吧!\n");	
    if ( userp(me) && me->query("age")>=18 && verb=="new" && !wizardp(me))
          return notify_fail("你已经不是新手了。\n");
if( userp(me) && !wizardp(me) && ((strsrch(arg,"(")!=-1 && strsrch(arg,")")!=-1) || (strsrch(arg,"（")!=-1 && strsrch(arg,"）")!=-1) || (strsrch(arg,"(")!=-1 && strsrch(arg,"）")!=-1) || (strsrch(arg,"（")!=-1 && strsrch(arg,")")!=-1) || strsrch(arg,"妈")!=-1 || strsrch(arg,"奶")!=-1 || strsrch(arg,"娘")!=-1 ))     	
return notify_fail(HIR"禁止的字符，请检查你的输入信息！\n"NOR);	
if (userp(me) && !wizardp(me) && verb=="xyxw")
return notify_fail("什么？\n");	
if (userp(me) && !wizardp(me) && verb=="jypm")	
return notify_fail("什么？\n");	
//if( userp(me) && !wizardp(me) && time()-me->query("birthday")<=1800)
	//return notify_fail(HIW"你刚出生"HIG+(int)(time()-me->query("birthday"))/60+HIW"分"HIG+(int)(time()-me->query("birthday"))%60+HIW"秒，还需等待"HIY+(int)(1800-(time()-me->query("birthday")))/60+HIW"分"HIY+(int)(1800-(time()-me->query("birthday")))%60+HIW"秒才能使用聊天频道。\n"NOR);
if(userp(me) && !wizardp(me) && me->is_ghost())
	return notify_fail("咦.....鬼魂也想说话？\n");

    }

    // Support of channel emote
    if( emote  && me->is_character() && !remote) {
        string vb, emote_arg, id, mud;

        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
            vb = arg;
            emote_arg = "";
            }

        if( channels[verb]["intermud_emote"]
            && sscanf(emote_arg, "%s@%s", id, mud)==2 ) {
                REMOTE_Q->send_remote_q(mud, verb, me->query("id"), id, vb);
                write("网路讯息已送出，请稍候。\n");
                return 1;
           }

        if( channels[verb]["intermud_emote"] )
            arg = EMOTE_D->do_emote(me, vb, emote_arg, 3);
        else if( verb == "rumor" && random(10)<8 )
            arg = EMOTE_D->do_emote(me, vb, emote_arg, 2, channels[verb]["anonymous"]);
        else    arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);

        if (!arg && emote) {
        // we should only allow chinese emote.
        if( (int)vb[0] < 160 ) return 0;
            arg = sprintf("%s(%s@%s)%s\n",me->name(),me->query("id"),Mud_name(),arg_bk);
            if( verb == "rumor" ) {
                if( userp(me) )
                    arg = sprintf("%s%s\n",channels[verb]["anonymous"],vb);
            }
        }
    if( !arg ) {
        if( channels[verb]["anonymous"] ) 
            arg = channels[verb]["anonymous"]+vb+" "+emote_arg+"\n"; 
        else if( channels[verb]["intermud_emote"] )
            arg = sprintf("%s(%s@%s)%s %s\n", me->name(1),
                capitalize(me->query("id")), INTERMUD_MUD_NAME, vb, emote_arg);
        else    arg = me->name()+vb+" "+emote_arg+"\n"; 
        }
    }

    
    // Make the identity of speaker.
    if( channels[verb]["anonymous"] ) {
        who = channels[verb]["anonymous"];
        if (userp(me))
         if (random(10)>8) who=me->name(1) + "(" + capitalize(me->query("id")) + ")";
         else
                do_channel( this_object(), "sys", sprintf("%s"+HIW+"躲在茅厕后面造谣。", me->short(1)));
    }   else if(me && (userp(me) || !stringp(who = me->query("channel_id")) )){
        if (me->name()!=me->name(1) && emote)
                do_channel( this_object(), "sys", sprintf(HIW"%s(%s)"+WHT+"扮%s!", me->name(1),me->query("id"),me->name()));
        who = me->name(1) + "("+capitalize(me->query("id"))+")";
    }

//  the channel "adm" modify by ken at 1998-06-19
    if( verb == "adm" ) {
        who = sprintf("%s", RANK_D->query_rank(me));
        who = replace_string(who," ","");
        who = replace_string(who,NOR,"");
        who +=(me->name(1)+"("+capitalize(me->query("id"))+")");
    }


    // Ok, now send the message to those people listening us.
        if (verb=="shout"){
                if (!me->query("family/family_name"))
                        return notify_fail(YEL"你还没有加入任何门派！\n"NOR); 
                ob_tomud=filter_array( users(), "family_listener_tomud", this_object(), me->query("family/family_name") );
                ob_zmud=filter_array( users(), "family_listener_zmud", this_object(), me->query("family/family_name") );

		}
		else
		{
                ob_tomud = filter_array( users(), "filter_listener_tomud", this_object(), channels[verb] );
                ob_zmud = filter_array( users(), "filter_listener_zmud", this_object(), channels[verb] );
        }
		
    if( !arg || arg == "" || arg == " " ) arg = "...";

    if( emote ) 
	{
        string localmsg;
        string ecol=channels[verb]["msg_color"];
        if(remote) {
            arg=arg_bk;
        }

        if (!stringp(arg)) return notify_fail("你要对谁做这个动作？\n");

        localmsg = arg;

        if ( channels[verb]["msg_emote"] )
		{
            localmsg = remove_addresses(arg, 0); // 98-1-22 14:30
		}

        if( channels[verb]["omit_address"] ) localmsg = remove_addresses(arg, 1);
        else if( channels[verb]["intermud_emote"] ) localmsg = remove_addresses(arg, 0);

        if(!stringp(localmsg)) return 0;
        
		if (verb=="shout")
		{
			message( "channel:" + verb,PTEXT(sprintf( channels[verb]["msg_emote"],me->query("family/family_name"), replace_string(localmsg,NOR,ecol) )), ob_tomud );
			message( "channel:" + verb,sprintf( channels[verb]["msg_emote"],me->query("family/family_name"), replace_string(localmsg,NOR,ecol) ), ob_zmud );
		}
		else
		{
			if((int)channels[verb]["small_window"])
			{
				message( "channel:" + verb,  PTEXT(sprintf( channels[verb]["msg_emote"],replace_string(localmsg,NOR,ecol))), ob_tomud );
				message( "channel:" + verb,  sprintf( channels[verb]["msg_emote"],replace_string(localmsg,NOR,ecol)), ob_zmud );
			}
			else
			{
				message( "channel:" + verb,  sprintf( channels[verb]["msg_emote"],replace_string(localmsg,NOR,ecol)), ob_zmud );
                                message( "channel:" + verb,  sprintf( channels[verb]["msg_emote"],replace_string(localmsg,NOR,ecol)), ob_tomud );
			}
		}
	}
	else
	{
		if (verb=="shout")
		{
			message( "channel:" + verb,PTEXT(sprintf( channels[verb]["msg_speak"],me->query("family/family_name"),who,arg+HIW" ["HIY+CHINESE_D->chinese_time(8,ctime(time()))+HIW"]"NOR )), ob_tomud );
			message( "channel:" + verb,sprintf( channels[verb]["msg_speak"],me->query("family/family_name"),who,arg+HIW" ["HIY+CHINESE_D->chinese_time(8,ctime(time()))+HIW"]"NOR ), ob_zmud );
		}
		else
		{
			if((int)channels[verb]["small_window"])
			{
				message( "channel:" + verb,  PTEXT(sprintf( channels[verb]["msg_speak"],who,arg+HIW" ["HIY+CHINESE_D->chinese_time(8,ctime(time()))+HIW"]"NOR)), ob_tomud );
				message( "channel:" + verb,  sprintf( channels[verb]["msg_speak"],who,arg+HIW" ["HIY+CHINESE_D->chinese_time(8,ctime(time()))+HIW"]"NOR), ob_zmud );
			}
			else
			{
				message( "channel:" + verb,  sprintf( channels[verb]["msg_speak"],who,arg), ob_tomud );
				message( "channel:" + verb,  sprintf( channels[verb]["msg_speak"],who,arg+HIW" ["HIY+CHINESE_D->chinese_time(8,ctime(time()))+HIW"]"NOR), ob_zmud );
			}
		}
	}

    if( arrayp(channels[verb]["extra_listener"]) ) {
        channels[verb]["extra_listener"] -= ({ 0 });
        if( sizeof(channels[verb]["extra_listener"]) )
            channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
        }
        
    if( !undefinedp(channels[verb]["intermud"]) && me->is_character()) {
        channels[verb]["intermud"]->send_msg(
        channels[verb]["channel"], me->query("id"), me->name(1), arg, emote,
        channels[verb]["filter"] );
    }
if (userp(me) && !wizardp(me)) {
		if (stringp(me->query_temp("last_channel_msg"))
			&& (strsrch(arg, me->query_temp("last_channel_msg")) >= 0
			|| strsrch(me->query_temp("last_channel_msg"), arg) >= 0))
			
			me->add_temp("channel_repeat", 1);
			
		else me->delete_temp("channel_repeat");
		
		if (me->query_temp("channel_repeat") > 2) {
			me->set("chblk_"+verb, time());
			switch (verb) {
				case "chat": verb = "闲聊"; break;
				case "rumor": verb = "谣言"; break;
				case "new": verb = "新手"; break;
				case "es": verb = "网际闲聊"; break;
				case "jh": verb = "夕阳再现"; break;
				default: verb = "交谈";
			}
			do_channel(this_object(), "rumor",
				"由于讲话过于罗嗦，" + me->name(1) + "("+capitalize(me->query("id"))+")的" + verb + "频道被噎死了。");
		}
			
	       me->set_temp("last_channel_msg", arg);
		
		if (me->add_temp("channel_count", 1) > 1) {
			me->delete_temp("channel_count");
			if (me->query_temp("last_channel_time") == uptime()) {
				me->set("chblk_"+verb, time());
				switch (verb) {
				case "chat": verb = "闲聊"; break;
				case "rumor": verb = "谣言"; break;
				case "new": verb = "新手"; break;
				case "es": verb = "网际闲聊"; break;
				case "jh": verb = "夕阳再现"; break;
				default: verb = "交谈";
				}
				do_channel(this_object(), "rumor",
					"由于讲话太多太快，" + me->name(1) + "("+capitalize(me->query("id"))+")的" + verb + "频道被噎死了。");
			}
			me->set_temp("last_channel_time", uptime());
		}
	}
    return 1;
}

int filter_listener_tomud(object ppl, mapping ch)
{
    // Don't bother those in the login limbo.
    if( !environment(ppl) ) return 0;
	if( ppl->query("xieyi/zmud") )  return 0;
    if(userp(ppl)){
    if( ch["arch_only"])
            if( userp(ppl) )
            if( wiz_level(ppl) < wiz_level("(arch)") )
                return 0;
    if( ch["adm_only"])
        if( userp(ppl) )
            if( wiz_level(ppl) < wiz_level("(admin)") )
                return 0;
    if( ch["wiz_only"] ) 
        if( userp(ppl) )    
            return wizardp(ppl);

    if( ch["es_only"] ) {
        if( wiz_level(ppl) > 0 ) return 1;
        if( ppl->query("age") > 23 ) return 1;
        return 0;
    }
}

    return 1;
}


int filter_listener_zmud(object ppl, mapping ch)
{
    // Don't bother those in the login limbo.
    if( !environment(ppl) ) return 0;
	if( !ppl->query("xieyi/zmud") )  return 0;
    if(userp(ppl)){
    if( ch["arch_only"])
            if( userp(ppl) )
            if( wiz_level(ppl) < wiz_level("(arch)") )
                return 0;
    if( ch["adm_only"])
        if( userp(ppl) )
            if( wiz_level(ppl) < wiz_level("(admin)") )
                return 0;
    if( ch["wiz_only"] ) 
        if( userp(ppl) )    
            return wizardp(ppl);

    if( ch["es_only"] ) {
        if( wiz_level(ppl) > 0 ) return 1;
        if( ppl->query("age") > 23 ) return 1;
        return 0;
    }
}

    return 1;
}

void register_relay_channel(string channel)
{
    object ob;
    ob = previous_object();
    if( undefinedp(channels[channel]) || !ob) return;
    if( arrayp(channels[channel]["extra_listener"]) ) {
    if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
    channels[channel]["extra_listener"] += ({ ob });
    }
    else  channels[channel]["extra_listener"] = ({ ob });
}

string remove_addresses(string msg, int all)
{
    int i;
    mixed tmp;
    string pattern;

    if(!stringp(msg)) return msg;
    if( all )
        pattern = "[(][A-Za-z]+@[a-zA-Z]+[0-9]+[.]?[)]";
    else
        pattern = "[(][A-Za-z]+@"+Mud_name()+"[)]";

    tmp = reg_assoc(msg, ({pattern}), ({1}));

    if(!arrayp(tmp)) return msg;
    msg = "";
    for(i=0; i< sizeof(tmp[0]); i++)
        if( tmp[1][i] == 0 ) msg += tmp[0][i];
    return msg;
}

int family_listener_zmud(object ppl, string str)
{
        // Don't bother those in the login limbo.
        if( !environment(ppl)) return 0;
        if( !ppl->query("xieyi/zmud") ) return 0;
        if( wizardp(ppl) || ppl->query("family/family_name")==str ) return 1;
        else return 0;
}

int family_listener_tomud(object ppl, string str)
{
        // Don't bother those in the login limbo.
        if( !environment(ppl)) return 0;
        if( ppl->query("xieyi/zmud") ) return 0;
        if( wizardp(ppl) || ppl->query("family/family_name")==str ) return 1;
        else return 0;
}
