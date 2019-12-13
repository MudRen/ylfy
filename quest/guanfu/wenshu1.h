#include <ansi.h>

void init()
{
        call_out("dest", 1800);
	add_action("do_guankan", ({"guankan","kan"}));
	add_action("do_wancheng", ({"wancheng","wancheng"}));
}

int do_guankan(string arg)
{
	int now_time, time;
	object me;

	me = this_player();
	now_time = me->query_condition("guanfu_task"); 
	time = me->query_temp("guanfu_time");

	if(!arg) return 0;
	if( arg=="wenshu" ) {
		write(
			"\n����һ������֪������׽�ý����������飬�������������Ļ���һ��"
"\n�˵�ͷ��������һ��С�֣�����д�ţ�\n����������"+me->query_temp("guanfu_target")+"��������׽�á���"
"�ݷɸ봫�飬�ķ�Ŀǰ��û�ڡ�"+me->query_temp("ch_weizhi")+"��������\n");
		if(now_time > time*3/4) write("�������г����ʱ��ȥѰ��Ŀ�ꡣ\n");
		if(now_time > time/2 && now_time <= time*3/4) write("�Ѿ���ȥһС��ʱ���ˡ�\n");
		if(now_time > time/4 && now_time <= time/2) write("�㻹��һ���ʱ��ȥ׷��Ŀ�ꡣ\n");
		if(now_time > time/8 && now_time <= time/4) write("���ʱ���Ѿ������ˡ�\n");
		if(now_time > 0 && now_time <= time/8) write("�ٸ������Ѿ������µ�Ŀ���ˣ���Ҫץ��ʱ���ˡ���\n");
		return 1;
	}
}

int do_wancheng(string arg)
{
// object ob;
	object me, target;
	int exp,pot,score,gfjob_times,now_time;

	if(!arg) return notify_fail("��Ҫ��ʲô��\n");
	me = this_player();
	target = present(arg, environment(me));
	now_time = me->query_condition("guanfu_task");

	if(!target) return notify_fail("�Ҳ������������\n");
	if(target->query("id") != "corpse") return notify_fail("�㲢û���������\n");
	if(target->query("victim_name") != me->query_temp("guanfu_target")) return notify_fail("�Ǹ�������Ŀ�꣡\n");
	if(target->query("victim_user")) return notify_fail("�ٺ٣������ף���\n");
        if(!me->query_temp("kill_by")) return notify_fail("������һ����Ŀ���Ѿ�����ɱ�ˡ�\n");
        if(target->query_temp("mark/dune1")) return notify_fail("���Ѿ���һ���Ѿ�����ɱ����ʬ���ˡ�\n");

	me->add("gf_job",1);
	gfjob_times=(int)me->query("gf_job");
	if (gfjob_times < 1) gfjob_times = 1;
    message_vision(HIW"$N��Цһ�����ӻ����ͳ����鿴�˿���΢���ھ�����������з����ȥ��"
"\n�������黯��ƬƬѩƬ��������$n���ϡ�\n"NOR, me, target);
    write(WHT"�ܺã���ɹ������������Ŀǰ���Ѿ�Ϊ�ٸ�����"+gfjob_times+"�ι��ס�\n"NOR);
	target->set("long", target->query("long")+"������������ֽƬ��\n");
        target->set_temp("mark/dune1",1);
//	if(me->query("potential") > me->query("max_pot")) 
//      me->set("potential", me->query("max_pot"));
	me->delete_temp("guanfu_time");
	me->clear_condition("guanfu_task");
	me->delete_temp("guanfu_target");
	me->delete_temp("ch_weizhi");
	me->delete_temp("path_rooms");
	me->delete_temp("gstart_rooms");
	me->delete_temp("mark/gkill3");
	me->delete_temp("kill_by");

	if ((int)me->query("combat_exp")<3000000){
         pot=350+random(me->query("max_pot")*3);
                if (pot > 1550) exp =1550;
         exp=(900+(random(15)*90));
		 score=random(81);
         me->add("potential",pot);
         me->add("combat_exp",exp);
         me->add("score",score);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
		 "��������������"+chinese_number(score)+"��\n"NOR);
         destruct(this_object());
         return 1;
	}
	if ((int)me->query("combat_exp")>3000000 && 
	me->query("combat_exp")<15000000){
         pot=360+random(me->query("max_pot")*4);
                if (pot >1500) pot =1500;
         exp=(1500+(random(20)*100)); 
		 score=random(81);
         me->add("potential",pot);
         me->add("combat_exp",exp);
		 me->add("score",score);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
		 "��������������"+chinese_number(score)+"��\n"NOR);
		destruct(this_object());
		return 1;
	}
	if ((int)me->query("combat_exp")>15000000 && 
         me->query("combat_exp")<50000000){
         pot=360+random(me->query("max_pot")*5);
                if (pot > 1550) pot =1550;
         exp=(2000+(random(30*100))); 
		 score=random(81);
         me->add("potential",pot);
         me->add("combat_exp",exp);
		 me->add("score",score);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
		 "��������������"+chinese_number(score)+"��\n"NOR);
         destruct(this_object());
         return 1;
	}
	if ((int)me->query("combat_exp")>50000000 && 
         me->query("combat_exp")<150000000){
         pot=360+random(me->query("max_pot")*9);
                if (pot > 1600) pot =1600;
         exp=(2500+(random(45*90))); 
         score=random(100);
         me->add("potential",pot);
         me->add("combat_exp",exp);
		 me->add("score",score);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
		 "��������������"+chinese_number(score)+"��\n"NOR);
         destruct(this_object());
         return 1;
	}
	if ((int)me->query("combat_exp")>150000000 && 
         me->query("combat_exp")<500000000){
         pot=100+random(me->query("max_pot")*10);
                if (pot > 1600) pot =1600;
         exp=(3000+(random(45*100))); 
		 score=random(150);
         me->add("potential",pot);
         me->add("combat_exp",exp);
		 me->add("score",score);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
		  "��������������"+chinese_number(score)+"��\n"NOR);
         destruct(this_object());
         return 1;
	}
   if ((int)me->query("combat_exp")>500000000) {
	pot=500+random(me->query("max_pot")*10);
                   if (pot > 1600) pot =1600;
	exp=(3500+(random(50*100)));
	score=random(150);
	me->add("potential",pot);
	me->add("combat_exp",exp);
	me->add("score",score);
	 tell_object(me,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
		"��������������"+chinese_number(score)+"��\n"NOR );
	destruct(this_object());
	return 1;
    }
}

void dest()
{
       object me;
       me = this_player();
       write("�����Ѿ��������ģ�������ˣ������Ѿ�ûʲ�����ˣ���ֻ�����ֶ�����\n", me);  
       destruct(this_object());
}
