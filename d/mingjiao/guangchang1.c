// Room: guangchang1.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�������̵����䳡��������缫ʢ��ÿ����Ҫ���������ᣬ��
����ڵ�ʱ�׷��׼��������д衣�����ܵý��з���������������Ϊ
��ͽ��������ͷ��ӵ�����ַǷ���������Ϊ׳�ۡ�������Ϊ���䳡��
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mingjiaodizi" : 3,
]));
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shiwangdian",
  "west" : __DIR__"lianwu-chang4",
  "south" : __DIR__"houtuqi",
  "east" : __DIR__"lianwu-chang2",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

