// shandong.c By csy 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIY"��ɽ��"NOR);
    set("long", @LONG
�ⶴ��ʵ��ǳ���в������ɣ��ѵ־�ͷ����ͷ���и�С��(dong)��ͨ��ɽ
�󡣶��г���һ��ʯ����һ��ʯ��֮����ޱ��������һ����ʯ���𣬼���
һ����Ĺ���������ƺ�д������(zi)��ֻ�ǳ���̦�Σ��ڰ����Ʋ������
LONG
        );

    set("item_desc", ([
           "zi" : HIY"\t\t�ݺὭ����ʮ���أ�ɱ����ܣ�
\t\t�ܾ�Ӣ�ۣ����¸��޿��֣�
\t\t�޿��ͺΣ�Ω������ȣ��Ե�Ϊ�ѡ�
\t\t�غ�����ƽ��һ���ֶ����ɵã��ϼ����ѿ�Ҳ��\n 
\t\t\t\t\t��ħ�������\n"NOR,
           "dong" : "�Ӷ���͸��һ˿������ʹ��ԭ���İ���ɽ���Գ�һ��������\n",
    ]));

    set("exits", ([ 
                "out"  : __DIR__"shanlu6",
    ]));
    
    setup();
}

void init()
{ 
      add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
      object me=this_player();
      if (me->is_busy() || me->is_fighting())
         return notify_fail("����æ���ģ�\n");
      if ( !arg || arg != "dong")
         return notify_fail("���������갡��\n");
      if ( arg=="dong")
if (random(2)==1)	 {
         me->move(__DIR__"shanlu7");
         message_vision(HIY"$Nһ������С���������ᣬֻ����ľ�Դ䣬ɽ����ѡ�\n"NOR,me);
}
else me->move(__DIR__"shushang");
         return 1;
}

