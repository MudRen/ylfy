// Room: juyiting.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������̾��������ǽ������µĵط���������������̸��ֶ�
��Ԫ�������������˷���ʱʱ���Լ�������ͬ���и�λ�����ڴ˹�
�̴�ƣ���ʱ����ͨ���ﵩ�����ղ��ߡ����а��ڽԾ�̾����

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shenghuo-tang",
  "west" : __DIR__"zoulang4",
  "south" : __DIR__"shiwangdian",
  "east" : __DIR__"zoulang3",
]));
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/fanyao" : 1,
__DIR__"npc/xunluo" : 3,
  __DIR__"npc/youzong" : 3,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

