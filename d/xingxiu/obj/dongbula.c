//  instrument: dongbula.c
// Jay 3/18/96
#include <ansi.h>
inherit ITEM;
int do_play(string arg);
//void setup()
//{}
void init()
{
        add_action("do_play", "play");
}
void create()
{
        set_name(HIY+"������"+NOR, ({"dongbula"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ά�����������������������������(play)����\n");
                set("value", 100);
        }
//        setup();
}
int do_play(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ����ʲô��\n");
        switch( random(3) ) {
                case 0:
                       say(this_player()->name() + "���𶬲���������س�����\n"
MAG "����ңԶ�ĵط�����λ�ù��ÿ�������߹�����ձ������Ҫ����\n" 
"�����������\n" + NOR);
            write(this_player()->name() + "���𶬲���������س�����\n"
MAG "����ңԶ�ĵط�����λ�ù��ÿ�������߹�����ձ������Ҫ����\n"
"�����������\n" NOR);
                        break;
                case 1:
                        say(this_player()->name() + "���𶬲��������ֵس�����\n"
HIY "����ǵ�ʯͷԲ��Ӳ����ϴ�����ඣ�����ǵĹ�����ӳ����ֻ�۾���Ư����\n" NOR);
            write(this_player()->name() + "���𶬲��������ֵس�����\n"
HIY "����ǵ�ʯͷԲ��Ӳ����ϴ�����ඣ�����ǵĹ�����ӳ����ֻ�۾���Ư����\n" NOR);
                        break;
                case 2:
                        say(this_player()->name() + "���𶬲��������˵س�����\n"
BLU "���̲�ϵ�һ����Ȫ����ɽ�ϵ�һ��ѩ�����籩������Զ��ͣ��\n"
"��������ʲôʱ�򰡣����ܼ������Ц����\n" NOR);
            write(this_player()->name() + "���𶬲��������˵س�����\n"
BLU "���̲�ϵ�һ����Ȫ����ɽ�ϵ�һ��ѩ�����籩������Զ��ͣ��\n"
"��������ʲôʱ�򰡣����ܼ������Ц����\n" NOR);
                        break;
        }
        return 1;
}
int query_autoload() { return 1; }