// Room: /d/kunlun/zhp.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
����һ���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ���ƹ�������
������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ���صĶ�����̯
������һ������(zhaopai)��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"wft",
]));
        set("item_desc", ([
                "zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
]));
        set("objects", ([
                __DIR__"npc/zhanggui": 1,
]));
        setup();
        replace_program(ROOM);
}
