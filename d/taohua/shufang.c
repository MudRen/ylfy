inherit ROOM;
void create()
{
    set("short", "�鷿");
    set("long", @LONG
    ����һ��ɸɾ������鷿������һ����̴ľ�������Ϸ��Ų����鼮��
��ǽ�ĵط�����һ����ܣ�����������ȫ�Ǹ��ַ�װ���顣���в�����
����ȥ���ⰻȻ����Ȼ����Ѿá�
LONG
    );
    set("exits", ([
    "west" : __DIR__"dating",
]));
     set("objects", ([
        __DIR__"npc/yapu" : 1,
        __DIR__"npc/yapu2" : 1,

//        __DIR__"obj/xiang" : 1,
    ]) );    
    setup();
    replace_program(ROOM);
}
