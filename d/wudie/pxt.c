// Room: /d/wudie/pxt.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "Ʈ��԰");
        set("long", @LONG
��һ��԰��һ�ɺ��ر����������������������������һ�ڣ���
���ƣ�ͺͼ�����ȫ��ʧ�ˡ�԰������һ��������������ʢ���ż���˶
��İ׻���ԭ������������׻����š���ǰһ�����㾪���ˣ�ǰ���Ȼ
��һƬ��ɫ�����ڶ������鲻�Խ��ӿ첽��......
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qjm",
  "north" : __DIR__"wdt",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
