// Room: jyentrance.c

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
���������̼�������ڣ�������Ȼ�����������ɣ���һ�����¹�������
���������Ѻ��һ���ǽ��������ж����Ĵ�����ɻ�����������˵���Ҳ
��Ѻ�����̵�һЩΥ��ĵ��ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shenghuo-tang",
  "north" : __DIR__"jianyu",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yu-zu" : 1,
  __DIR__"npc/lengqian" : 1,
]));
        set("no_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && objectp(present("leng qian", environment(me))))
                return notify_fail(
"��ǫ�ȵ������������صأ���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
        return ::valid_leave(me, dir);
}

