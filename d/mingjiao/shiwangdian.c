// Room: shiwangdian.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����Ϊ���������⸸����ӥ�̽����ع����̵�׳�ٶ������
���ã���ʾ�������¾���ǰ�ӡ�ͬ��Э���������������ľ��ġ�����
������¯��̨���������ڴ�Ч�������ţ���Ϊ�����ֵܡ�

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zoulang2",
  "south" : __DIR__"guangchang1",
  "north" : __DIR__"juyiting",
  "east" : __DIR__"zoulang1",
]));
        set("no_clean_up", 0);

set("objects",([ __DIR__"npc/fuwang":1,
        __DIR__"npc/yingwang":1,
]));
        setup();
        replace_program(ROOM);
}

