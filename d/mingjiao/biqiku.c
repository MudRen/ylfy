// Room: bingqiku.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǽ��еı����⣬��ǹ��ꪡ����ṳ��ʮ�˰������һӦ��
ȫ����������ķ����˼�ʮ�ű����ܣ�һ���´���ĵ�����Сɽһ��
�ѷ��ڿ��ſڵĵط�������������æ�������ϼܣ���ʱ����һ�����
ײ���ġ����~��֮����

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zoulang2",
]));
        set("objects", ([ /* sizeof() == 3 */
  __DIR__"obj/guangmingjian" : 3,
  __DIR__"obj/guangmingdao" : 3,
  __DIR__"npc/mingjiaodizi" : 1,
  __DIR__"obj/muchui" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

