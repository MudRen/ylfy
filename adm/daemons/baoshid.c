#include <ansi.h> 
inherit F_DBASE; 
#define BAOSHI_UPDATE_TIME 3600

string *baoshis=({
        "/clone/gem/gem",
		"/clone/gem/gem",
		"/clone/gem/gem",
		"/clone/map/obj/jingang-shi",
		"/clone/map/obj/jingang-shi",
		"/clone/map/obj/jingang-shi",
		"/clone/map/obj/hanyu-jingtie",
		"/clone/map/obj/hanyu-jingtie",
		"/clone/map/obj/hanyu-jingtie",
		"/clone/map/obj/longwen-chijin"
        });

void create() 
{
    seteuid(getuid());
    set("channel_id", "宝石精灵");
    CHANNEL_D->do_channel( this_object(), "sys", "宝石精灵已经启动。\n"NOR);
    set_heart_beat(BAOSHI_UPDATE_TIME);
}

void choose_baoshi();
private void heart_beat()
{
    choose_baoshi();
}

private string baoshi_place;
void choose_baoshi() 
{
    int i,n,ran;
    object *user=users();
    object room,baoshi;
    mapping exits;
    string msg,roompath;
    n = sizeof(user);
    if(n<10)
        return;
    for(i=0;i<10;i++)
    {
        ran = random(n);
        if(!living(user[ran]))
            continue;
        if(wizardp(user[ran]))
                continue;
	if(user[ran]->is_ghost()) continue;
        room = environment(user[ran]);
        if(!room || !objectp(room))
            continue;
        exits=room->query("exits");
        if(!exits || !mapp(exits))
            continue;
        roompath = file_name(room);
        if(strsrch(roompath,"/d/migong/")==0 ||
                strsrch(roompath,"/adm/daemons/vrm_server/")==0)
            continue;
        baoshi = new(baoshis[random(sizeof(baoshis))]);
		//baoshi = new(baoshis[sizeof(baoshis)]);
        baoshi->move(room);
        msg = sprintf("宝石掉落在%s(%s)\n",room->query("short"),roompath);
        CHANNEL_D->do_channel( this_object(), "sys", msg);
	break;
    }
    return ; 
} 

