//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","�Է�");
  set ("long", @LONG

�ܼ��ӵķ��䣬���������, ��������������Ӱ˵��飬
ǽ����һ������ɫ�����(bed)��
LONG);

  set("no_fight", 1);
  set("objects",([
"/d/shushan/zhenyaota/obj/leizhu":1,
  ]));
  set("item_desc", ([
  "bed" : "һ������ɫ����齣������ܵ�����Ҷ�񣬿���ȥ��Ϊ����(gobed)�� 
",
]));
  set("exits", ([
  "east" : __DIR__"midao1",
]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gobed", );
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
        me->move(__DIR__"bed");
            message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me);
                return 1;
}



