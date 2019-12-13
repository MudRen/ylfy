//伐毛洗髓丹

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
    set_name( HIG "伐毛洗髓丹" NOR , ({"famaoxisui dan", "dan"}));
    set_weight(90);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("unit", "颗");
	set("long", "一颗绿色的丹丸，据说用了("HIW"xisui"NOR")可以脱胎换骨。\n");
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
	tell_object(me,"你放弃使用洗髓伐毛丹。\n");
	return;
    }
    if(sscanf(arg,"%d %d %d %d",bili,wuxing,jingu,shenfa) != 4)
    {
	tell_object(me,"输入格式不对\n");
	return;
    }
    if(total != (bili+wuxing+jingu+shenfa))
    {
	tell_object(me,"属性点总和与原有总和不等\n");
	return;
    }
	if(80 != (bili+wuxing+jingu+shenfa))
    {
	tell_object(me,"你先天属性不等于80，所以无法使用\n");
	return;
    }
	if(bili>30||wuxing>30||jingu>30||shenfa>30)
    {
	tell_object(me,"每项属性最大值是30\n");
	return;
    }
    if(bili<10||wuxing<10||jingu<10||shenfa<10)
    {
	tell_object(me,"每项属性最小值是10\n");
	return;
    }
    me->set("str",bili);
    me->set("int",wuxing);
    me->set("con",jingu);
    me->set("dex",shenfa);
    tell_object(me,HIR"你张大嘴巴，把伐毛洗髓丹往嘴里一扔，伐毛洗髓丹顿时化成一股甘流往你的四肢百骸散去！\n"NOR);
    tell_object(me,sprintf(HIW"你的先天属性变为：【臂力：%d】【悟性：%d】【根骨：%d】【身法：%d】\n"NOR,
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
	return notify_fail("你正忙着呢！\n");
    if(me->is_fighting())
	return notify_fail("战斗中伐毛洗髓，我看你是活腻了\n");
    total += me->query("str");
    total += me->query("int");
    total += me->query("con");
    total += me->query("dex");
    printf("你的先天属性点一共是"HIW"%d"NOR"点\n",total);
    write("请分别输入你想要的臂力、悟性、根骨、身法，用空格分开。输入0取消。\n");
    input_to("set_attr",me,dan,total);
    return 1;
}

int do_eat(string arg)
{
    write("这东东不能直接吃，要xisui。\n");
    return 0;
}

int query_autoload() { return 1; }

