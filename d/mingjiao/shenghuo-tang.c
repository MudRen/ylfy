// Room: shenghuo-tang.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"ʥ����"NOR);
        set("long", 
"�����������ʥ�������ڡ����Ϸ���һ���������顸"RED"ʥ����"NOR"����
��Ѫ����֡�����ǽ�ϵ�ʯ���п���һ�ž޴�Ļ�����棬�������ϣ�
��֮���������߸�����һ���ַ���\n"
HIY @LONEA
�����Ҳ���������ʥ������λ�������οࣿΪ�Ƴ���Ω�����ʣ���
��ϲ�ֱ���Թ鳾�����������ˣ��ǻ�ʵ�࣡�������ˣ��ǻ�ʵ�ࡣ��
LONEA
NOR @LONEB
���ڽ���������������ʢ��ǰ�����ݵĽ����������ﲻ��������ǽ�Ϲ�
���˷ÿ����µĳ���֮�ʡ��������н����ı������������ŷ��л�����
�ڡ�����ͨ��������Ϣ�ĺ�Ժ�������Ǿ�������
LONEB
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"juyiting",
  "west" : __DIR__"xiaoting",
  "east" : __DIR__"jyentrance",
]));
        set("objects", ([
  __DIR__"npc/mingjiaodizi" : 4,
__DIR__"npc/zhangwuji" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


