//��ëϴ�赤

#include <ansi.h>
inherit ITEM;
void init()
{
    add_action("do_famaoxisui", "famaoxisui");
    add_action("do_famaoxisui", "famao");
    add_action("do_famaoxisui", "xisui");
}

void create()
{
    set_name( HIG "��ëϴ�赤" NOR , ({"famaoxisui dan", "dan"}));
    set_weight(90);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("unit", "��");
	set("long", "һ����ɫ�ĵ��裬��˵����("HIW"xisui"NOR")������̥���ǡ�\n");
	set("value", 200000000);
	set("no_sell",1);
	set("no_drop",1);
    }
}

protected void set_attr(string arg,object me,object dan,int total)
{
    int bili,wuxing,jingu,shenfa;
    if(arg=="0")
    {
	tell_object(me,"�����ʹ��ϴ�跥ë����\n");
	return;
    }
    if(sscanf(arg,"%d %d %d %d",bili,wuxing,jingu,shenfa) != 4)
    {
	tell_object(me,"�����ʽ����\n");
	return;
    }
    if(total != (bili+wuxing+jingu+shenfa))
    {
	tell_object(me,"���Ե��ܺ���ԭ���ܺͲ���\n");
	return;
    }
	if(80 != (bili+wuxing+jingu+shenfa))
    {
	tell_object(me,"���������Բ�����80�������޷�ʹ��\n");
	return;
    }
	if(bili>30||wuxing>30||jingu>30||shenfa>30)
    {
	tell_object(me,"ÿ���������ֵ��30\n");
	return;
    }
    if(bili<10||wuxing<10||jingu<10||shenfa<10)
    {
	tell_object(me,"ÿ��������Сֵ��10\n");
	return;
    }
    me->set("str",bili);
    me->set("int",wuxing);
    me->set("con",jingu);
    me->set("dex",shenfa);
    tell_object(me,HIR"���Ŵ���ͣ��ѷ�ëϴ�赤������һ�ӣ���ëϴ�赤��ʱ����һ�ɸ����������֫�ٺ�ɢȥ��\n"NOR);
    tell_object(me,sprintf(HIW"����������Ա�Ϊ����������%d�������ԣ�%d�������ǣ�%d��������%d��\n"NOR,
	me->query("str"),me->query("int"),me->query("con"),me->query("dex")));
    me->save();
    me->start_busy(5);
    destruct(dan);
}

int do_famaoxisui(string arg)
{
    object me = this_player();
    object dan = this_object();
    int total = 0;
    if(me->is_busy())
	return notify_fail("����æ���أ�\n");
    if(me->is_fighting())
	return notify_fail("ս���з�ëϴ�裬�ҿ����ǻ�����\n");
    total += me->query("str");
    total += me->query("int");
    total += me->query("con");
    total += me->query("dex");
    printf("����������Ե�һ����"HIW"%d"NOR"��\n",total);
    write("��ֱ���������Ҫ�ı��������ԡ����ǡ������ÿո�ֿ�������0ȡ����\n");
    input_to("set_attr",me,dan,total);
    return 1;
}

int do_eat(string arg)
{
    write("�ⶫ������ֱ�ӳԣ�Ҫxisui��\n");
    return 0;
}

int query_autoload() { return 1; }

