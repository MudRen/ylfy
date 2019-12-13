// 馅饼

#include <ansi.h>

inherit ITEM;

int do_chieat(string);
void init();

void init()
{
  add_action("do_chieat", "chieat");
}

void create()
{
  set_name( HIY "馅饼" NOR , ({"pie", "xian bing"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "个");
set("no_get", 1);	
set("no_put", 1);	
set("no_drop", 1);	
set("no_give", 1);	
    set("long", "这是一个天上掉下的馅饼，已经有几千年的历史了，据说练武的人吃了会奇效无比，但是功力不够者也可能会死！总之没人实验过，也没人遇到过!  据说这个馅饼还是中西合并料理的哦：） \n");
set("value", 2000);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}
int do_chieat(string arg)
{
  object me = this_player();

  if (arg!="pie" && arg!="xian bing")   return 0;
if (me->query("combat_exp",1)<100000000)
{
		message_vision("$N吃下一个馅饼，痛的满地打滚，不一会就呜呼了。。。\n", me);
		me->die();
               CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s吃馅饼吃死了。", me->name(1)));
		destruct(this_object());
}
if (me->query("max_neili",1)<800000)
{
		message_vision("$N吃下一个馅饼，但是由于你的内力不足以抗拒馅饼的强大威力，血管爆裂而亡。。。\n", me);
		me->die();
                CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s吃馅饼吃死了。", me->name(1)));
                destruct(this_object());
}
if (me->query("combat_exp",1)>100000000)
	{
  message_vision(HIG " $N狼吞虎咽的吃下一个馅饼，突然肚子一阵翻滚 \n" NOR, me);
  call_out("eat1",1,me);
	}
return 1;
}

int eat1(object me)
{
  message_vision(HIG " $N环顾四周 ,没茅厕。。。怎么办？。。。\n" NOR, me);
  call_out("eat2",1,me);
  return 1;
}

int eat2(object me)
{
  message_vision(HIG " 哎，顾不得面子了，就地解决吧！\n" NOR, me);
  call_out("eat3",1,me);
  return 1;
}

int eat3(object me)
{
  write(HIG " 经过一阵折腾后，你感觉自己的身体有些变化。\n" NOR);
  call_out("eat4",1,me);
  return 1;
}

int eat4(object me)
{
  write(HIG " 恭喜你，快打HP看看，有什么变化！\n" NOR);
me->add("potential",10000);	
  destruct(this_object());
  return 1;
}

//   void owner_is_killed() { destruct(this_object()); }             	
