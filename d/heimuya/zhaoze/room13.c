// Room: room13.c
inherit ROOM;
string* npcs = ({
    "/d/shenlong/npc/jinshe",
    "/d/shenlong/npc/qingshe",
    "/d/shenlong/npc/jinshe",
    "/d/shenlong/npc/qingshe",
    "/d/shenlong/npc/fushe",
}); 
void create()
{
        set("short", "ɭ��");
        set("long", @LONG
ǰ�����û��·�����ܵ������г������Ӳ�(weed)�������ܲ���
Ũ�ܿ�����Ҷ�ڱ��������ǳ���ʹ�˷ֲ�����ҹ����������һ���
�ž���ֻ�з紵�����ҵ�ɳɳ֮����
LONG
        );

    set("exits", ([
        "east" : __DIR__"room12",
    ]));

    set("item_desc", ([
        "weed" : "��Ƭ�Ӳ�̫����,Ҫ���ȥ����ֻ�п���һ��·��(kan)��\n",
    ]));
        set("objects", ([
    "/d/shenlong/npc/dushe" : 1+random(2),
    npcs[random(sizeof(npcs))] : 1,
    npcs[random(sizeof(npcs))] : 1,
    npcs[random(sizeof(npcs))] : 1,
    ]) );

        setup();
}
void init()
{
    add_action("do_kan", "kan");
}
int do_kan ( string arg )
{
    object weapon;
    if( !arg || arg !="weed" ) 
         return notify_fail("��Ҫ��ʲô��\n" ) ;
    if (!objectp(weapon = this_player()->query_temp("weapon")))
        return notify_fail("�����������²��аɣ�\n");
        message_vision(
        "$N�������,�����Ӳ�һ���ҿ���\n", this_player());
        if(this_player()->query("neili")>100)
    {
        set("exits/north", __DIR__"room16");
        message_vision(
        "$N�۵���������,���ڿ���һ��С·��\n", this_player());
        this_player()->add("neili",-50);
        remove_call_out("close");
        call_out("close", 20, this_object());
    }
        else    
    {
        message_vision(
        "$N�۵���������,Ҳû����һ��·����\n", this_player());
    this_player()->set("neili",0);
    }
return 1;
}
void close(object room)
{
    message("vision","�Ӳݽ�����£����,�����ָֻ���ԭ״��\n", room);
    room->delete("exits/north");
}
