// Room: /d/wudie/dyt.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һ��ƽ�أ������ŵ������ĵط�����Ϊ�ʵ���Ҫ����ʱ��
��ɵ���������������������ǳ��΢�紵����ƬƬ�ʵ��ĳ�����
���裬���ŵ����������������˿�����ѧ---��������
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"pjt",
  "south" : __DIR__"cdt",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
