// By zjb@ty 2002-5-15

#include <ansi.h> 
inherit ROOM; 
int do_dan(object me,object obj);
int do_yao(object me,object obj);
void create()
{
        set("short", HIY"������"NOR);
        set("long", @LONG
�����ǻ�٢��������,�����������һ������¯,
����ǿ��������Լ��ھ����Ĳ�ҩ�����Լ�����ĵ���ҩ!
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

    if(!arg) return notify_fail("��Ҫ��ʲôҩ��ȥ��\n");

    if( !me->query_temp("zhuyao"))
    return notify_fail("����Ҫ�ȷ���ҩ,Ҫ��Ȼ�������õ�!\n");

    if( !objectp(obj = present(arg, me)) )
    return notify_fail("�����ϲ�û����������!\n");

    return do_dan(me, obj);

}

int do_zhuyao(string arg)
{
    object obj;
    object me = this_player();

    if(!arg) return notify_fail("��Ҫ��ʲô��������ҩ��\n");

    if( !objectp(obj = present(arg, me)) )
    return notify_fail("�����ϲ�û����������!\n");

  if(me->is_busy())
  return notify_fail("��������æ,��һ�����ڰ�!\n");


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

    if (!arg) return notify_fail("��Ҫ���ĸ�����ĵ���\n");

    if (!me->query_temp("liandan"))
    return notify_fail("��û�ŵ�,������ƨ!\n");


// By zjb@ty ���¶������Ʋзϵ�ҩ������
    if (arg == "shoubi") {
    me->add("combat_exp",1000);
    me->delete_temp("zhuyaoname");
    me->delete_temp("danname");

    
// By zjb@ty �����Ķ��⽱��!
    me->add("combat_exp",zjb*1000+random(1000));
    me->add("potential",zjb*100+random(500));
    me->start_busy(5);
    write(HIR"����������ʱ��֪��������Ҳ������ȥ��!\n"NOR);

    if (shoubi==32 && zhuyao==1) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    dan=new("/d/yao/obj/shoubi1");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"�����������Ʊ��˵���ҩ��ҩ��!\n"NOR);
    }
    if (shoubi==26 && zhuyao==2) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/shoubi2");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIB"�����������Ʊ��˵���ҩ������!\n"NOR);
    }
    if (shoubi==27 && zhuyao==3) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");    
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/shoubi3");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"�����������Ʊ��˵���ҩ�ȸ���!\n"NOR);
    }
    if (shoubi==33 && zhuyao==4) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/shoubi4");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"�����������Ʊ��˵���ҩ����Ѫ����!\n"NOR);
    }

    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/chayao");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"����䷽���󲻶�,����һ������ҩƷ!\n"NOR);
    }

    if (arg == "tui") {
    me->add("combat_exp",1000);
    me->delete_temp("zhuyaoname");
    me->delete_temp("danname");
    
// By zjb@ty �����Ķ��⽱��!
    me->add("combat_exp",zjb*1000+random(1000));
    me->add("potential",zjb*100+random(500));
    me->start_busy(5);
    write(HIR"����������ʱ��֪��������Ҳ������ȥ��!\n"NOR);

    if (tui==74 && zhuyao==11) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/tui1");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIC"���������������˵���ҩ--��Ѫֹʹ��!\n"NOR);
    }
    if (tui==151 && zhuyao==12) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/tui2");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"���������������˵���ҩ--���Ͻӹ�ɢ!\n"NOR);
    }

    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/chayao");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"����䷽���󲻶�,����һ������ҩƷ!\n"NOR);
    }
    
    if (arg == "all") {
    me->add("combat_exp",1000);
    me->delete_temp("zhuyaoname");
    me->delete_temp("danname");

// By zjb@ty �����Ķ��⽱��!
    me->add("combat_exp",zjb*1000+random(1000));
    me->add("potential",zjb*100+random(500));
    me->start_busy(5);
    write(HIR"����������ʱ��֪��������Ҳ������ȥ��!\n"NOR);

    if (all==51 && zhuyao==21) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/all1");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"������������ʥҩ--�����ɢ!\n"NOR);
    }
    if (all==64 && zhuyao==22) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/all2");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"������������ʥҩ--���嵤!\n"NOR);
    }
    if (all==40 && zhuyao==23) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/all3");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"������������ʥҩ--׳�����ǵ�!\n"NOR);
    }
    if (all==55 && zhuyao==24) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/all4");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"������������ʥҩ--��ɰûҩɢ!\n"NOR);
    }
    
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/chayao");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"����䷽���󲻶�,����һ������ҩƷ!\n"NOR);
    }

// By zjb@ty ��������������ĳ���!    
    if (arg == "random") {
    me->add("combat_exp",1000);
    me->delete_temp("zhuyaoname");
    me->delete_temp("danname");
    
// By zjb@ty �����Ķ��⽱��!
    me->improve_skill("liandan-shu", me->query_int()*300+random(100));
    me->add("combat_exp",zjb*1000+random(1000));
    me->add("potential",zjb*100+random(500));
    me->start_busy(5);
    write(HIR"����������ʱ��֪��������Ҳ������ȥ��!\n"NOR);

    if ( liandan > 500 && zjb > 15) {
    if ( zjb>15 && zjb<20 && all2 < 211 &&all2 > 100 
    && random(10000)>9995) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan11");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(BLINK HIR"�㾹Ȼ�����˿���ʹ�������Ļ��굤!!!\n"NOR);
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
    return notify_fail(HIC"�������˿�������ȫ���书�ļ��ܵ�!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>3 && all2 < 200 && all2 > 30 
    && random(100)>60) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan12");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIB"�������˿���ʹ�˷��ϻ�ͯ���ɵ�!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>95) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan6");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿���������������ı�����!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>95) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan7");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿�������������������!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>95) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan8");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿�������������ǵĸ��ǵ�!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>95) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan9");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿��������������Ե����Ե�!!!\n"NOR);
    }

   if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>20) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan23");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿��������湦���湦��!!!\n"NOR);
    }

    if ( zjb < 15 && zjb>10 && all2 < 150 && all2 > 40 
    && random(100)>95) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan10");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿�������������ò�����յ�!!\n"NOR);
    }

    }

    if ( zjb==2 &&all2 < 100 && all2 > 1 ) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/clone/drug/yangjing");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIY"���������ƾ��õ�������!\n"NOR);
    }


    if ( zjb < 4 && zjb > 1 && all2 < 100  && all2 > 5 ) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/clone/drug/jinchuang");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIY"�������������õĽ�ҩ!\n"NOR);
    }

    if ( zjb < 8 && zjb>3 && all2 < 100 && all2 > 30 && random(10)>4
    && zhuyao >= 1 && zhuyao < 5) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan2");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"�������˿�ʹ�Լ�ʹ�Լ�����busy�ļ��絤\n"NOR);
    }
    
    if ( zjb < 6 && zjb > 3 && all2 < 100 && all2 > 20 
    && random(10)>4&& zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan3");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"������������ʥҩ������!\n"NOR);
    }
    
    if ( zjb < 10 && zjb > 4 && all2 < 100 && all2 > 20 
    && random(10)>4&& zhuyao >= 11 && zhuyao < 15) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan4");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"������������ʥҩ�󻹵�!\n"NOR);
    }

    if ( zjb < 6 && zjb > 3 && all2 < 100 && all2 > 20 
    && random(10)>4&& zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan5");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"�������˲���ʥҩ,����!!!\n"NOR);
    }

    if ( zjb < 10 && zjb > 2 && all2 < 100 && all2 > 10 
    && random(10)>3 && zhuyao >= 1 && zhuyao < 5) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan13");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"�������˿ɽ�ٶ��Ľⶾ��!!!\n"NOR);
    }

    if ( zjb < 10 && zjb > 2 && all2 < 100 && all2 > 10 
    && random(10)>3 && zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan14");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"�������˿����ӹ�������ս����!!!\n"NOR);
    }

    if ( zjb < 15 && zjb > 2 && all2 < 100 && all2 > 30 
    && random(10)>8 && zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan15");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIG"�������˿����Ӽ��ܵ�����!!!\n"NOR);
    }

    if ( zjb < 7&& zjb > 2 && all2 < 100 && all2 > 20 &&random(10)>4
    && zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan1");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿�ʹ�Լ�״̬�ָ�����Ѫ����!\n"NOR);
    }

    if ( zjb < 10 && zjb > 3 && all2 < 100 && all2 > 10 
    && random(10)>2 && zhuyao >= 1 && zhuyao < 5) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan16");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIB"�������˿�����������������!!!\n"NOR);
    }

    if ( zjb < 15 && zjb > 3 && all2 < 150 && all2 > 30 
    && random(10)>3 && zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan17");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿����ӻ����ڹ���̫����!!!\n"NOR);
    }

    if ( zjb < 15 && zjb > 1 && all2 < 150 && all2 > 10 
    && random(10)>3 && zhuyao >= 1 && zhuyao < 5) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan18");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿����ӻ��������а����!!!\n"NOR);
    }

    if ( zjb < 15 && zjb > 3 && all2 < 150 && all2 > 30 
    && random(10)>8 && zhuyao >= 11 && zhuyao < 15) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan20");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿����ӻ����Ṧ�ľ�����!!!\n"NOR);
    }

    if ( zjb < 15 && zjb > 3 && all2 < 150 && all2 > 30 
    && random(10)>3 && zhuyao >= 1 && zhuyao < 5) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan21");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿����ӻ���ȭ�ŵ�������!!!\n"NOR);
    }

    if ( zjb < 10 && zjb > 4 && all2 < 150 && all2 > 50 
    && random(10)>3 && zhuyao >= 21 && zhuyao < 25) {
    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/dan22");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIR"�������˿����Ӷ���д�ֵ�������!!!\n"NOR);
    }

    me->delete_temp("liandan");
    me->delete_temp("zhuyao");
    me->delete_temp("zjb_dan");
    dan = new("/d/yao/obj/chayao");
    dan->set("zhuren",""+me->query("id")+"");
    dan->move(me);
    return notify_fail(HIW"��˴�����ʧ��,����һ������ҩƷ!\n"NOR);
}
    }

int do_dan(object me,object obj)
{
    object ob;
    string arg=obj->short(1);
  
    foreach ( ob in all_inventory(me)){
    if (ob->short(1)!=arg) continue;
    if (!ob->query("yao")) {
    write("��������������������ҩ!\n");
    return 1;
    }

    if (me->query_temp("danname/"+ob->query("id")+""))
    return notify_fail("���Ѿ���"+ob->name()+"�Ž�����¯��!\n");

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
    write(HIR"���"+ob->name()+HIR"�Ž�������¯!\n"NOR);
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
    return notify_fail("�Բ������Ѿ���"+me->query_temp("zhuyaoname")+"����ҩ��!\n");

    foreach ( ob in all_inventory(me)){
    if (ob->short(1)!=arg) continue;
    if (!ob->query("zhuyao")) {
    write("������������������ҩ!\n");
      return 1;
    }
    write(HIR"����"+ob->name()+HIR"����ҩ!\n"NOR);
    me->set_temp("zhuyao",ob->query("zhuyao"));
    me->set_temp("zhuyaoname",""+ob->name()+"");
    destruct(ob);
    return 1;
    }
}


