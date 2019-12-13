// Room: /d/kunlun/bwc.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
string look_men();
void create()
{
        set("short", "���䳡");
        set("long", @LONG
����վ��һ������Ĵ󷿼���, �����������ɵ��Ӵ��������ĵط�, ����
��������һ�ɹɺ���ζ�����ܵ�ǽ���ϻ���һ��������Ѩ��ͼ������ǽ�ڵĵ�
�������һ���������õ�ľ�ˡ�������һ����(men)�������������š�
LONG
        );
    set("objects", ([ 
        CLASS_D("kunlun")+"/xihuazi"  : 1,
        CLASS_D("kunlun")+"/weisiniang"  : 1,
    ]));
        set("exits", ([ 
  "north" : __DIR__"dt",
  "south" : __DIR__"klpsm",
  "east" : __DIR__"pqf",
  "southwest" : __DIR__"wgws",
]));

    set("item_desc",([
        "men"        :    (: look_men :),
]));

        setup();
}
void init()
{
    add_action("do_knock", "knock");
    add_action("do_push", "push");
    add_action("do_open", "open");
}
int do_open(string arg)
{
    if (query("exits/west"))
        return notify_fail("���Ѿ��ǿ����ˡ�\n");
    if (!arg || (arg != "door" && arg != "men"))
        return 0;
    this_player()->add_temp("open_men",1);
    if (this_player()->query_temp("open_men")>5){
        this_player()->delete_temp("open_men");
        return notify_fail("����ֻ������(push)�����ܽ�ȥ!��!!!!\n");
    }
    else    return notify_fail("������Ť��һ������,�������ַ����ƺ�����!\n");
}
void close_men()
{
    object room;
    if(!( room = find_object(__DIR__"xis")) )
        room = load_object(__DIR__"xis");
    if(objectp(room))
    {
        delete("exits/west");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", this_object());
        room->delete("exits/east");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", room);
    }
    else message("vision", "ERROR: men not found(close).\n", room);
}
int do_knock(string arg)
{
    object room;
    if (query("exits/west"))
        return notify_fail("�����Ѿ��ǿ����ˡ�\n");
    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("��Ҫ��ʲô��\n");
    if(!( room = find_object(__DIR__"xis")) )
        room = load_object(__DIR__"xis");
        
    if(objectp(room))
    {
    if ((int)room->query_temp("sleeping_person") > 0)
    {
        message_vision(
        "$N�����������һ���ţ����������洫��һ���������������\n"
    "��Ȼ�������˯�ø������Ƶģ���ô�ö�û����\n",
        this_player());
    } else if ((int)room->query_temp("person_inside") > 0)
    {
        switch( random(2) )
        {
        case 0:
            message_vision(
            "$N������������ţ�ֻ�����������˺ܲ��ͷ��غ𵽣�\n"
        "�����¾������ţ���˯���ˣ�������������\n",
            this_player());
            
            break;
        case 1: 
            message_vision(
            "$N������������ţ�ֻ����������Щ�춯��\n"
        "����������������ȥ���ò��������Ƿ��š�\n",
            this_player());
            
            break;
    }           
                
    } else
    {
    room->delete_temp("sleeping_person");
        message_vision("$N������������ţ��ˡ��ˡ��ˣ������ˡ��ˡ��ˣ�����\n",
            this_player());
    }
    }
    if(objectp(room))
        message("vision",
        "���洫��һ��������������ŷ�����һ�ƣ���"+this_player()->query("name")+"һ��������վ�����⣬\n"
        "������Ҳ�������Ϣ��\n", room);
        
    return 1;
}
int do_push(string arg)
{
    object room;
    if (query("exits/west"))
        return notify_fail("���Ѿ��ǿ����ˡ�\n");
    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("��Ҫ��ʲô��\n");
    if(!(room = find_object(__DIR__"xis")))
        room = load_object(__DIR__"xis");
        
    if(objectp(room))
    {
    if((int)room->query_temp("person_inside")<=0)
    {
        room->delete_temp("person_inside");
        set("exits/west", __DIR__"xis");
        message_vision("$N����ذ����ƿ���\n", this_player());
        room->set("exits/east", __FILE__);
        message("vision", "���˴���������ƿ��ˡ�\n", room);
        remove_call_out("close_men");
        call_out("close_men", 10);
    } else 
    {
        message_vision("$N������ƿ���ȴ�����ű��˴����������ˡ�\n",
        this_player());
    }
    }
    return 1;
}
string look_men()
{
    object room;
    if (query("exits/east"))
    return ("���Ϲ��˸����ӣ��Ͽ��δ���\n");
    if(!( room = find_object(__DIR__"xis")) )
        room = load_object(__DIR__"xis");
    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
    return ("���Ϲ��˸����ӣ��������\n");
    } 
    
    return ("���Ϲ��˸����ӣ���Ϣ��\n");
}
int valid_leave(object me, string dir)
{
        object room;
        
    if(!( room = find_object(__DIR__"xis")) )
            room = load_object(__DIR__"xis");
    if(objectp(room) && dir == "west")
    {
        if (room->query_temp("person_inside"))
            return notify_fail("û���������Ѿ���������\n");
        room->add_temp("person_inside", 1);
        // will open the door if ppl inside stay too long 
        remove_call_out("force_open");
        call_out("force_open", 100, room);
    }       
    return ::valid_leave(me, dir);
}
int force_open(object room)
{
    object *env;
    int i;
    if ( !objectp(room) ) return 0;
    if((int)room->query_temp("person_inside")<=0) return 0;
    room->delete_temp("person_inside");
    set("exits/west", __DIR__"xis");
    room->set("exits/east", __FILE__);
    message("vision", "����ͻȻ������صĽŲ�������Զ����������ǰͣ������������\n"
        "������ž�ذ��Ŵ򿪣����ͷ������һ�����ɣ���������˻�����ȥ����ʲô��\n", room);
    env=all_inventory(room);
    if (sizeof(env))
        for(i=0;i<sizeof(env);i++)
            if (userp(env[i])){
                env[i]->move(this_object());
                message_vision("������һ��ץס$N�����죬���˳���!\n", env[i]);
                message("vision", "������һ��ץס"+env[i]->name()+"�����죬���˳�ȥ!\n",room);
                }
    remove_call_out("close_men");
    call_out("close_men", 10);
    return 1;
}
