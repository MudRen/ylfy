// Room: /d/lingjiu/liangong.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "Ϸ���");
    set("long", @LONG
���������չ����������ĵط����м�������Ů������ר�����µ�����
���м����ֳ���,�ڻ������,���鶯�����紩������һ�㣬�㲻����
�����ۣ�����������ڵ��ϵ������Ͽ���������
LONG
    );
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"changl4",
]));
    set("objects", ([ /* sizeof() == 1 */
  "/d/shaolin/npc/mu-ren" : 6,
]));
    setup();
    replace_program(ROOM);
}
