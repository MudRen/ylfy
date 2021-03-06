// kuihua.c 葵花宝典原本 用来解谜的
// by.suimeng    2015.3.19
inherit ITEM;
void setup()
{}
void init()
{
     if (this_player()==environment()){
        add_action("do_lingwu", "lingwu");
    }
}
void create()
{
        set_name(YEL"葵花宝典", ({ "kuihua baodian"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这就是武林第一秘籍《葵花宝典》的原本，这本和江湖上流传的有什么不同呢？可以参透(lingwu)下。\n");
                set("value", 50000);
                set("material", "paper");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
        }
}

int do_lingwu(string arg)
{
	object me = this_player();       
	int ap;
	
  string *poem = ({
		"应定心圆气，舍却心中杂念，存想天女捧香而至，气自丹田而生,经右肾旋而下右足，由足后反上右胁下。",
		"华池液满，分三次咽下，前后共反复三十六次，功行百日，可颜如婴童！。",
		"气入泥丸，搬运不停，华池之液咽四十九之数，气固而成真。此境界行之久久，可令气化为真。",
		"保肾得铅养心得汞，铅汞升降相遇于金鼎中而成丹，二气无本则铅汞不生，二气本源固密则日进千里。",
		"扫除尘垢，反朴归真，澄明寂然，可以妙洞三界，无所不能。",
		"其法将真气升之，两手相叠，左手压右手，右手摩顶，三千功后自化神。",
		"气生之法，思色是苦。厌苦舍离，以达性静。性静以后，手若拈花。气绕任脉诸穴，方汇丹田。",
		});

    if(me->is_busy() )
          return notify_fail("你现在忙着呢，哪有功夫领悟葵花宝典上的东西...\n");
    
    if((int)me->query_skill("literate",1) < 5000 )
               return notify_fail("你仔细参悟了葵花宝典，但是一脸茫然。\n");
    
	ap = me->query_skill("literate", 1) /1000;
	
	if (me->query_skill("kuihua-xinfa",1) < 3000)
        {
        tell_object(me,"似乎......葵花心法.............\n"); 
        return 1;
        }

    if(me->query("jing") < 1000)
        {
        tell_object(me,"你还是先休息一会儿吧。\n");     
        return 1;
        }
        message_vision("$N仔细的领悟着葵花宝典的奥秘：" + poem[random(sizeof(poem))] + "\n", me);
        me->add("jing",-100);
        me->start_busy(2);
		
    if(me->query("kuihua/rao_perform")) 
        {
        tell_object(me,"你已经完全领悟了葵花心法的精髓，不需要在领悟了。\n");       
        return 1;
        }
    if((int)me->query_skill("kuihua-xinfa", 1) > 3000)
		{
        tell_object(me,HIW"你仔细研究这本原版的《葵花宝典》，尝试着练习了下......\n"NOR);                	
        me->start_busy(2);
        }
    if( random(500000) < me->query("kar") + ap)
        {
        me->add("kuihua/rao_perform",1);
        tell_object(me,HIG"你突然醒悟道："HIY"原来葵花宝典精髓竟然在此!!!"HIR"！\n"NOR);      				
        }
        return 1;
}             
int query_autoload() { return 1; }