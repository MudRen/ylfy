// gshedan.c ������

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(MAG"������"NOR, ({"dumang dan", "mangdan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������ɫ�ȳ�Բ��\n");
                set("no_drop", 1);                
                set("no_give", 1);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        if ( me->query_skill_mapped("force") != "yunv-xinjing"){
                me->add("max_neili", -10);
                message_vision(HIR "$N����ҧ��һ��Բ��ֻ���øγ���ϣ���������ѵ���\n" NOR, me);
                me->unconcious();
                destruct(this_object());
                return 1;
        }
        if ( me->query("max_neili") < 400 ){
                me->add("max_neili", -1);
                message_vision(HIR "$N����ҧ��һ��Բ��ֻ��֭Һ�ȼ��༫���ѳ��ޱȣ�ԭ�������������Եֵ�ҩЧ��\n" NOR, me);
        }
        else if ( (int)me->query_condition("bonze_drug" ) > 0 ){
                me->add("max_neili", -1);
                message_vision(HIR "$N����ҧ��һ��Բ��ֻ��֭Һ�ȼ��༫���ѳ��ޱȣ�ԭ��Ƶ����ҩ�ݲ��ֵܵ�ҩЧ��\n" NOR, me);
        }
        else {
                me->add("max_neili", random(1) + 1);
                message_vision(HIG "$N����ҧ��һ�£�Բ����Ƥ�㼴���ѣ���ʱ���ڿ�֭��������һ�ᣬ
�����������������˳���������������ʤƽʱ�� \n" NOR, me);
        }
        me->apply_condition("bonze_drug", 25);
        destruct(this_object());
        return 1;
}
int query_autoload() { return 1; }
