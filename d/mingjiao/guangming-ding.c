// Room: guangming-ding.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"������"NOR);
        set("long",
"����������̹����������ߵ�����ɿ��������ƽ�ɫ���֡���
�̣����֣�ؤ�������������Ḷ̌��������������ɣ���ؤ������
�����ɡ��������ɲ�˹�̴ܽ�����ԭ����һ�ٶ������ʷ�ˡ�����
ʼ�ն��Է�Ԫ����������ȥ�񣬳�������Ϊ���ѵ���ּ������������
̫�����½�������ݹݬ���룬��ʹ���������ɳ�Ϊħ�̡���������
һ���ɫ����Ĵ��졣�������᷿�����������á�"

"
                   "HIY"��    ��    ��"NOR"

"
        );
        set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tingtang",
  "north" : __DIR__"houtuqi",
  "east" : __DIR__"xiangfang_1",
  "southwest" : __DIR__"qian-ting",
]));
        set("objects", ([ /* sizeof() == 2 */
__DIR__"npc/xunluo" : 3,
  __DIR__"npc/yangxiao" : 1,
  __DIR__"npc/zuozong" : 3,
]));
        set("no_clean_up", 0);

        setup();
        "/clone/board/mingjiao_b"->foo();
        replace_program(ROOM);

}

