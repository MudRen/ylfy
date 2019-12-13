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
        set("short", "��ľ��");
        set("long",@LONG
����һƬ��ľ�֡����˲�Զ,��Ϳ��Կ��ü�ǰ��Ŀյ��ˡ�
LONG);
    set("exits", ([
        "north" : "/d/shenlong/kongdi",
        "south" : "/d/shenlong/lin1",
    ]));
        set("objects", ([
    "/d/shenlong/npc/dushe" : 1+random(2),
    npcs[random(sizeof(npcs))] : 1,
    npcs[random(sizeof(npcs))] : 1,
    npcs[random(sizeof(npcs))] : 1,
    ]) );
        set("outdoors", "shenlong");
        setup();
    replace_program(ROOM);
}
