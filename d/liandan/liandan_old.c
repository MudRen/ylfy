// By zjb@ty 2002-5-15

#include <ansi.h> 
inherit ROOM; 
int do_dan(object me,object obj);
int do_yao(object me,object obj);
void create()
{
        set("short", HIY"炼丹房"NOR);
        set("long", @LONG
这里是华佗的炼丹室,房间中央放着一个炼丹炉,
玩家们可以拿着自己挖掘来的草药练出自己所需的丹丹药!
LONG
        );
        set("exits", ([
		"east" : "/d/changan/ca14",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

void init()
{ 
        add_action("do_zhuyao","zhuyao");
        add_action("do_fangdan","fangyao");
        add_action("do_liandan","liandan"); 
}

int do_fangdan(string arg)
{
    object obj;
    object me = this_player();

    if(!arg) return notify_fail("你要放什么药进去？\n");

    if( !me->query_temp("zhuyao"))
    return notify_fail("练丹要先放主药,要不然练不出好丹!\n");

    if( !objectp(obj = present(arg, me)) )
    return notify_fail("你身上并没有这样东西!\n");

    return do_dan(me, obj);

}

int do_zhuyao(string arg)
{
    object obj;
    object me = this_player();

    if(!arg) return notify_fail("你要拿什么东西当主药？\n");

    if( !objectp(obj = present(arg, me)) )
    return notify_fail("你身上并没有这样东西!\n");

  if(me->is_busy())
  return notify_fail("您现在正忙,等一下再挖吧!\n");


    return do_yao(me, obj);

}

int do_liandan(string arg)
{
    int shoubi,tui,all,zhuyao,all2,zjb,liandan;
    object dan;
    object me = this_player();
    shoubi = me->query_temp("liandan/shoubi");
    tui = me->query_temp("liandan/tui");
    all = me->query_temp("liandan/all");
    all2 = me->query_temp("liandan/random");
    zhuyao = me->query_temp("zhuyao");
    zjb = me->query_temp("zjb_dan");
    liandan = me->query_skill("liandan-shu",1);

    if (!arg) return notify_fail("你要练哪个种类的丹？\n");

    if (!me->query_temp("liandan"))
    return notify_fail("你没放丹,你练个屁!\n");


// By zjb@ty 以下都是治疗残废的药的练法
    if (arg == "shoubi") {
    me->add("combat_exp",1000);
    me->delete_temp("zhuyaoname");
    me->delete_temp("danname");

    
// By zjb@ty 炼丹的额外奖励!
    me->add("combat_exp",zjb*1000+random(1000));
    me->add("potential",zjb*100+random(500));
    me->start_busy(5);
    write(HIR"你在炼丹的时候不知不觉经验也随着上去了!\n"NOR);

    if (shoubi==32 && zhuyao==1) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    dan=new("/d/yao/obj/shoubi1");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了治疗臂伤的良药伤药丸!\n"NOR);
    }
    if (shoubi==26 && zhuyao==2) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/shoubi2");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIB"你练出了治疗臂伤的良药补伤丸!\n"NOR);
    }
    if (shoubi==27 && zhuyao==3) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");    
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/shoubi3");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了治疗臂伤的良药先复汤!\n"NOR);
    }
    if (shoubi==33 && zhuyao==4) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/shoubi4");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了治疗臂伤的良药复方血竭酊!\n"NOR);
    }

    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/chayao");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"你的配方好象不对,练出一个无名药品!\n"NOR);
    }

    if (arg == "tui") {
    me->add("combat_exp",1000);
    me->delete_temp("zhuyaoname");
    me->delete_temp("danname");
    
// By zjb@ty 炼丹的额外奖励!
    me->add("combat_exp",zjb*1000+random(1000));
    me->add("potential",zjb*100+random(500));
    me->start_busy(5);
    write(HIR"你在炼丹的时候不知不觉经验也随着上去了!\n"NOR);

    if (tui==74 && zhuyao==11) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/tui1");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIC"你练出了治疗腿伤的良药--活血止痛汤!\n"NOR);
    }
    if (tui==151 && zhuyao==12) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/tui2");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了治疗腿伤的良药--宋氏接骨散!\n"NOR);
    }

    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/chayao");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"你的配方好象不对,练出一个无名药品!\n"NOR);
    }
    
    if (arg == "all") {
    me->add("combat_exp",1000);
    me->delete_temp("zhuyaoname");
    me->delete_temp("danname");

// By zjb@ty 炼丹的额外奖励!
    me->add("combat_exp",zjb*1000+random(1000));
    me->add("potential",zjb*100+random(500));
    me->start_busy(5);
    write(HIR"你在炼丹的时候不知不觉经验也随着上去了!\n"NOR);

    if (all==51 && zhuyao==21) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/all1");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了疗伤圣药--祛腐生肌散!\n"NOR);
    }
    if (all==64 && zhuyao==22) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/all2");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了疗伤圣药--七厘丹!\n"NOR);
    }
    if (all==40 && zhuyao==23) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/all3");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了疗伤圣药--壮筋续骨丹!\n"NOR);
    }
    if (all==55 && zhuyao==24) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/all4");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了疗伤圣药--朱砂没药散!\n"NOR);
    }
    
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/chayao");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"你的配方好象不对,练出一个无名药品!\n"NOR);
    }

// By zjb@ty 以下是随机炼丹的程序!    
    if (arg == "random") {
    me->add("combat_exp",1000);
    me->delete_temp("zhuyaoname");
    me->delete_temp("danname");
    
// By zjb@ty 炼丹的额外奖励!
    me->improve_skill("liandan-shu", me->query_int()*300+random(100));
    me->add("combat_exp",zjb*1000+random(1000));
    me->add("potential",zjb*100+random(500));
    me->start_busy(5);
    write(HIR"你在炼丹的时候不知不觉经验也随着上去了!\n"NOR);

    if ( liandan > 500 && zjb > 15) {
    if ( zjb>15 && zjb<20 && all2 < 211 &&all2 > 100 
    && random(10000)>9995) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan11");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(BLINK HIR"你竟然练出了可以使人重生的还魂丹!!!\n"NOR);
    }
    }

   if ( liandan > 300 && zjb > 10 && random(100)>70) {

    if ( zjb < 15 && zjb>10 && all2 < 200 && all2 > 100 
    && random(100)>90) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan19");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIC"你练出了可以增加全部武功的技能丹!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>3 && all2 < 200 && all2 > 30 
    && random(100)>60) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan12");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIB"你练出了可以使人返老还童的仙丹!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>95) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan6");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可以增加先天臂力的臂力丹!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>95) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan7");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可以增加先天身法的身法丹!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>95) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan8");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可以增加先天根骨的根骨丹!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>95) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan9");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可以增加先天悟性的悟性丹!!!\n"NOR);
    }

   if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>20) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan23");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可以增加奇功的奇功丸!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>95) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan10");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可以增加先天容貌的养颜丹!!\n"NOR);
    }

    }

    if ( zjb==2 &&all2 < 100 && all2 > 1 ) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/clone/drug/yangjing");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIY"你练出了疗精用的养精丹!\n"NOR);
    }


    if ( zjb < 4 && zjb > 1 && all2 < 100  && all2 > 5 ) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/clone/drug/jinchuang");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIY"你练出了疗伤用的金创药!\n"NOR);
    }

    if ( zjb < 8 && zjb>3 && all2 < 100 && all2 > 30 && random(10)>4
    && zhuyao >= 1 && zhuyao < 5) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan2");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了可使自己使自己脱离busy的疾风丹\n"NOR);
    }
    
    if ( zjb < 6 && zjb > 3 && all2 < 100 && all2 > 20 
    && random(10)>4&& zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan3");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"你练出了少林圣药菩提子!\n"NOR);
    }
    
    if ( zjb < 10 && zjb > 4 && all2 < 100 && all2 > 20 
    && random(10)>4&& zhuyao >= 11 && zhuyao < 15) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan4");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"你练出了少林圣药大还丹!\n"NOR);
    }

    if ( zjb < 6 && zjb > 3 && all2 < 100 && all2 > 20 
    && random(10)>4&& zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan5");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"你练出了补精圣药,肾宝!!!\n"NOR);
    }

    if ( zjb < 10 && zjb > 2 && all2 < 100 && all2 > 10 
    && random(10)>3 && zhuyao >= 1 && zhuyao < 5) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan13");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了可解百毒的解毒丸!!!\n"NOR);
    }

    if ( zjb < 10 && zjb > 2 && all2 < 100 && all2 > 10 
    && random(10)>3 && zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan14");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了可增加攻击力的战神丸!!!\n"NOR);
    }

    if ( zjb < 15 && zjb > 2 && all2 < 100 && all2 > 30 
    && random(10)>8 && zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan15");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"你练出了可增加技能的龙丹!!!\n"NOR);
    }

    if ( zjb < 7&& zjb > 2 && all2 < 100 && all2 > 20 &&random(10)>4
    && zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan1");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可使自己状态恢复满的血气丹!\n"NOR);
    }

    if ( zjb < 10 && zjb > 3 && all2 < 100 && all2 > 10 
    && random(10)>2 && zhuyao >= 1 && zhuyao < 5) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan16");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIB"你练出了可增加正气的正气丸!!!\n"NOR);
    }

    if ( zjb < 15 && zjb > 3 && all2 < 150 && all2 > 30 
    && random(10)>3 && zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan17");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可增加基本内功的太级丹!!!\n"NOR);
    }

    if ( zjb < 15 && zjb > 1 && all2 < 150 && all2 > 10 
    && random(10)>3 && zhuyao >= 1 && zhuyao < 5) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan18");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可增加基本负神的邪神丸!!!\n"NOR);
    }

    if ( zjb < 15 && zjb > 3 && all2 < 150 && all2 > 30 
    && random(10)>8 && zhuyao >= 11 && zhuyao < 15) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan20");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可增加基本轻功的惊风丸!!!\n"NOR);
    }

    if ( zjb < 15 && zjb > 3 && all2 < 150 && all2 > 30 
    && random(10)>3 && zhuyao >= 1 && zhuyao < 5) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan21");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可增加基本拳脚的神力丸!!!\n"NOR);
    }

    if ( zjb < 10 && zjb > 4 && all2 < 150 && all2 > 50 
    && random(10)>3 && zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan22");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"你练出了可增加读书写字的智力丸!!!\n"NOR);
    }

    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/chayao");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"你此次炼丹失败,练出一个无名药品!\n"NOR);
}
    }

int do_dan(object me,object obj)
{
    object ob;
    string arg=obj->short(1);
  
    foreach ( ob in all_inventory(me)){
    if (ob->short(1)!=arg) continue;
    if (!ob->query("yao")) {
    write("这样东西并不能拿来练药!\n");
    return 1;
    }

    if (me->query_temp("danname/"+ob->query("id")+""))
    return notify_fail("你已经把"+ob->name()+"放进练丹炉了!\n");

    if (ob->query("shoubi"))
    me->add_temp("liandan/shoubi",ob->query("shoubi"));

    if (ob->query("tui"))
    me->add_temp("liandan/tui",ob->query("tui"));

    if (ob->query("all"))
    me->add_temp("liandan/all",ob->query("all"));

    if (ob->query("random"))
    me->add_temp("liandan/random",ob->query("random"));

    me->set_temp("danname/"+ob->query("id")+"",1);
    me->add_temp("zjb_dan",1);
    write(HIR"你把"+ob->name()+HIR"放进了炼丹炉!\n"NOR);
    destruct(ob);
    return 1;
    }
}

int do_yao(object me,object obj)
{
    object ob;
    string arg=obj->short(1);
    me = this_player();
 
    if (me->query_temp("zhuyao"))
    return notify_fail("对不起你已经拿"+me->query_temp("zhuyaoname")+"做主药了!\n");

    foreach ( ob in all_inventory(me)){
    if (ob->short(1)!=arg) continue;
    if (!ob->query("zhuyao")) {
    write("这样东西并不能做主药!\n");
      return 1;
    }
    write(HIR"你拿"+ob->name()+HIR"做主药!\n"NOR);
    me->set_temp("zhuyao",ob->query("zhuyao"));
    me->set_temp("zhuyaoname",""+ob->name()+"");
    destruct(ob);
    return 1;
    }
}


