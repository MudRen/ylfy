// guojing.c ����
inherit NPC;

#include <ansi.h>
//#include "zzzjob.c"
//#include "teamjob.c"

string *random_item = ({
	"/clone/map/weapon/axe",
	"/clone/map/weapon/blade",
	"/clone/map/weapon/club",
	"/clone/map/weapon/dagger",
	"/clone/map/weapon/fork",
	"/clone/map/weapon/hammer",
	"/clone/map/weapon/ring",
	"/clone/map/weapon/spear",
	"/clone/map/weapon/staff",
	"/clone/map/weapon/whip",
	"/clone/map/weapon/sword",
	});

string ask_newjob();
string ask_newover();
int job_over(string arg);

void create()
{
	set_name("����", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"����"NOR);
	set("gender", "����");
	set("age", 41);
	set("long", 
		"�������˳Ʊ����Ĺ����������ɹųɼ�˼���Ľ���������\n"
		"�����߹֡�ȫ�������ڵ���������ؤ�����߹��͡�����ͯ����\n"
		"��ͨ���˵�ͽ�ܣ���������书��������һ����ɫ���ۣ���̬\n"
		"���࣬�غ����Ŀ��͸��һ�����ϡ�\n");
	set("attitude", "friendly");
	set_max_encumbrance(100000000);
	set("xy_shoucheng",1);
	set("no_suck", 1);
	set("end_boss", 1);
	set("per", 20);
	set("str", 30000);
	set("int", 20);
	set("con", 30000);
	set("dex", 30000);
	set("no_get", 1);
	set("no_put", 1);
        set_temp("no_get",1);
        set_temp("no_kill",1);
	set("chat_chance", 1);
	set("chat_msg", ({
		"����̾�˿����������ɹű��ù��������£�һ�����ٳ���ƣ��ض��ֲ�����ߣ���....\n",
		"����˵���������ݹ���������֪�ɺã����һ��Ҫ�ش�Įȥ��������\n",
//		(: random_move :),
	}));

	set("inquiry", ([
/*		"�ܲ�ͨ" : "��������ܴ���ˣ������ڿɺã�\n",
		"����ͯ" : "�ܴ��һ��������û��������\n",
		"���߹�" : "ʦ�����˳ԣ�����ϲ���档�����棬����Ϊ���ҳԵġ�\n",
		"��ҩʦ" : "������̩ɽ���ˡ��������ĺ����������ײ���β�ġ�\n",
		"һ�ƴ�ʦ" : "���¶Դ�ʦ�����м���\n",
		"ŷ����" : "����϶����������λʦ����һ���������ˣ������������ݡ�\n",
		"����"   : "�ض����ҵİ��ޣ�������������\n",
		"�ض�"   : "�ض������ض��ˡ�������ô����\n",
		"��ܽ"   : "���Ů�����ֱ��ֲ�������\n",
		"����"   : "��������������Ⱳ���ֶ��򡣵�Ը���ܿ���һ����\n",
		"����²" : "�����ҵ�С���ӡ�\n",
		"���"   : "����ȷʵ�г�Ϣ��\n",
		"����"   : "����������а�ʦ֮�ꡣ\n",
		"�𴦻�" : "������屡���죬������ܡ�\n",
		"�����" : "�����Ҵ�ʦ����\n",
		"���"   : "�����Ҷ�ʦ����\n",
		"������" : "��������ʦ����\n",
		"��ϣ��" : "��������ʦ����\n",
		"�Ű���" : "��������ʦ����\n",
		"ȫ��" : "��������ʦ����\n",
		"��СӨ" : "��������ʦ����\n",
		"ؤ��"   : "ؤ��Ӣ�ۼ������ˣ�����������������ǡ�\n",
		"��ʦ"   : "�����ɹ���Χ��������������������ͽ����\n",
		*/
      //"job"   : (: ask_job :),
      //"����"  : (: ask_gonglao :),
      //"fangqi": (: ask_fangqi :),
      //"����"  : (: ask_fangqi :),
      //"��ϸ"  : (: ask_jianxi :),
           "�س�" : (: ask_newjob :),
		   "����" : (: job_over :),
//                "job2"  : (: ask_newjob :),
     //           "����"  : (: ask_newover :),
		]));

	set("qi", 3000000);
	set("eff_qi", 3000000);
	set("max_qi", 3000000);
	set("jing", 3000000);
	set("eff_jing", 3000000);
	set("max_jing", 3000000);
	set("neili", 300000000);
	set("max_neili", 24000);
	set("max_jingli", 50000);
	set("jingli", 300000);
	set("jiali", 30000);
	
	set("combat_exp", 2100000000);
	set("score", 200000);
	 
	set_skill("force", 30000);		// �����ڹ�
	set_skill("huntian-qigong", 30000);	// ��������
	set_skill("unarmed", 30000);		// ����ȭ��
	set_skill("xianglong-zhang", 30000);	// ����ʮ����
	set_skill("dodge", 30000);		// ��������
	set_skill("xiaoyaoyou", 30000);		// ��ң��
	set_skill("parry", 30000);		// �����м�
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	prepare_skill("unarmed","xianglong-zhang");
	setup();
	
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("job_over","task");
}

string ask_newjob()
{
        object *ene;
        object me = this_player();

        if(is_fighting()) 
        {
                ene=query_enemy();
                
                if(sizeof(ene)>1) return "����"+RANK_D->query_respect(me)+"�Ե�Ƭ�̣����Ⱥ���"+sizeof(ene)+"λ�����д輸�£���\n";
                if(sizeof(ene)==1) return "����"+RANK_D->query_respect(me)+"�Ե�Ƭ�̣����Ⱥ�"+ene[0]->name()+"�д輸�£���\n";
        }

        if(me->query_temp("mark/job_shadi")>0 ) return "��"+RANK_D->query_respect(me)+"���������������𣡡�\n";

/*        if((int)me->query("shen") < 0) return "��"+RANK_D->query_respect(me)+"�������������ǲ���ӭ����\n";
*/     
        //if ((int)me->query("combat_exp")<100000) return "��"+RANK_D->query_respect(me)+"���޸���֮�������Ǳ��������Ϊ�ã���\n";

    if ( (int)me->query_skill("force",1) < 100 )
       return "�س��Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(me)+"�Ļ����ڹ����㣡\n";

    //if ( (int)me->query("combat_exp") < 100000 )
      // return "�س��Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(me)+"�ľ��鲻�㣡\n";

      if ((int)me->query_condition("jobshadi_failed"))
{
     message_vision("$N����$nҡ��ҡͷ˵������ʧ���˻�������??\n", this_object(), me);
return "��"+RANK_D->query_respect(me)+"�㻹�Ǳ��������Ϊ�ã���\n";
//return;
}

      if ((int)me->query_condition("jobshadi_limit")>1)
{
     message_vision("$N����$nҡ��ҡͷ˵���㲻����������??\n", this_object(), me);
	 me->set_temp("mark/job_shadi",2);
return "��"+RANK_D->query_respect(me)+"�������ĸ�λ��ȥ����\n";
//return;
}

if ( me->query("xyzx_sys/level") >= 500 )
		return (HIR"���Ѿ������ٴ��س������л��۸���ľ��飬����¥���������Ҫ���������ȥ���ԡ�\n"NOR);
	/*if ( (me->query("combat_exp")+me->query("xyzx_sys/levup_exp"))/LEVUP_EXP+me->query("xyzx_sys/level") < 7 )
		return (HIR"����Ŀǰ���������޷������س����Σ��㻹����ȥͨ������ĥ���������ɡ�\n"NOR);*/
   /*if ((int)me->query_condition("guojob2_busy"))
{
     message_vision("$N����$nҡ��ҡͷ˵�������ɹ������ڹ��ǣ���\n", this_object(), me);
return "��"+RANK_D->query_respect(me)+"��Ȼ���������\n";
//return;
}*/
message("channel:chat", HIB"����͢������"GRN + "����Ϣ˵���ɹ���������Ҫ�ַ�������!\n"NOR,users() );
        switch( random(4) ) {
                case 0:
			me->set_temp("mark/job_shadi",1);
        	        me->set_temp("carry_location","northgate1");		
                me->apply_condition("guojob2_busy",5);
                return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ�������Ű����ξ��سǰɡ�";

	               break;
                case 1:
			me->set_temp("mark/job_shadi",2);
                	me->set_temp("carry_location","northgate1");		
                me->apply_condition("guojob2_busy",5);
                return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ�������Ű����ξ��سǰɡ�";

	               break;
                case 2:
                	me->set_temp("mark/job_shadi",3);
                	me->set_temp("carry_location","southgate1");
                me->apply_condition("guojob2_busy",5);
                return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ��ȸ���Ű����ξ��سǰɡ�";

	               break;
                case 3:
                	me->set_temp("mark/job_shadi",4);
                	me->set_temp("carry_location","southgate1");
                me->apply_condition("guojob2_busy",5);
                return "�������ɹ������ַ���ԭ����λ"+RANK_D->query_respect(me)+"ȥ�׻����Ű����ξ��سǰɡ�";

	               break;
        	}
}

int job_over(string arg)
{
        int job_pot,job_exp, m;
        object me = this_player();
		object badguy;
		object room, baoshi;

        /*if(!arg) return 1;

        if(arg!="over") return 1;*/
	if(me->query_temp("help_killed")>0)
	{
        	message_vision(CYN "$N������$n�ļ��˵������"+RANK_D->query_respect(me)+"��Ϊ��ɱ�У���������\n" NOR, this_object(), me);
	        job_exp=((int)me->query_temp("killed_mgb"))*(100+random(100));
                  job_pot=job_exp/3;
                  job_exp=job_exp;
	        me->add("combat_exp", job_exp);
	        me->add("potential",job_pot);
tell_object(me, "�㱻������"+chinese_number(job_exp)+"�㾭��ֵ��\n"+chinese_number(job_pot)+"��Ǳ��\n");
	        me->delete_temp("killed_mgb");        
                me->delete_temp("job_over");
                me->delete_temp("mark/job_shadi");
                me->delete_temp("help_killed");
                me->delete_temp("start_job");
        receive_wound("jing",me->query("max_jing")/10);
        receive_wound("qi",me->query("max_qi")/10);
        me->start_busy(3);
                me->apply_condition("guojob2_busy",1);
        	return 1;
        }
        	
        if(me->query_temp("mark/job_shadi")==0)
        {
                message_vision(CYN"$N����$nһ��:��û����ʲô��ɲ���ɡ���\n",this_object(),me);
				me->delete_temp("killed_mgb");
				me->delete_temp("start_job");
                return 1;
        }
        
        if(me->query_temp("job_over")==0)
        {
                message_vision(CYN"$N����$nһ��:������û��ɣ������Ͽ�ص���ĸ�λ��ȥ����\n"NOR,this_object(),me);
				me->delete_temp("killed_mgb");
				me->delete_temp("start_job");
                return 1;
        }

       if(me->query_temp("killed_mgb")<2)
       {
                  message_vision(CYN"$N����$nһ��:����ɱ�˼������ˣ��㻹�����ͣ������Ͽ�ص���ĸ�λ��ȥ����\n"NOR,this_object(),me);
			me->delete_temp("killed_mgb");
         me->delete_temp("job_over");
         //me->delete_temp("mark/job_shadi");
		 me->delete_temp("start_job");
                  return 1;
          }

        message_vision(CYN "$N��$n˵������"+RANK_D->query_respect(me)+"�����ˣ�ȥ��Ϣһ�°ɣ���\n" NOR, this_object(), me);
        me->delete_temp("job_over");
        me->delete_temp("mark/job_shadi");
		me->delete_temp("start_job");
        job_exp=((int)me->query_temp("killed_mgb"))*(555+random(300));
        job_pot=job_exp/3;
		if (job_exp >100000) job_exp=100000;
		if (job_pot >33333) job_pot=33333;
tell_object(me, "�㱻������"+chinese_number(job_exp*me->query_exp_times())+"�㾭��ֵ��\n"+chinese_number(job_pot)+"��Ǳ�ܺ�50�㽭��������\n");
        me->apply_condition("guojob2_busy",1);
        me->add("combat_exp", job_exp);
        me->add("potential",job_pot);
        me->delete_temp("killed_mgb");        
        me->receive_wound("jing",me->query("max_jing")/10);
        me->receive_wound("qi",me->query("max_qi")/10);
        me->add("score",50);
        me->start_busy(3);
		// ��Ʒ����
		if ( random(100) < 5 )
		{
			m = random(sizeof(random_item));
			baoshi = new(random_item[m]);
			//if ( m < 2 )
				message("party", HIR"�������顿:"+HIG"��˵ "HIC+me->name(1)+HIW" �ɹ���������������������"HIM" һ"+baoshi->query("unit")+baoshi->name(1)+HIW"��\n"NOR, users());	
			tell_object(me, "������һ"+baoshi->query("unit")+baoshi->name(1)+NOR"��\n");	
			baoshi->set("xyzx_sys/bind_type", 0);
			baoshi->move(me);
		} 
		else if ( random(100) > 85 )
		{
			baoshi = new("/quest/baoshi/baoshis/baoshi");
			tell_object(me, "������һ"+baoshi->query("unit")+baoshi->name(1)+NOR"��\n");	
			baoshi->set("xyzx_sys/bind_type", 0);
			baoshi->move(me);
		}
        if (random(4) == 0)
        {
message("channel:chat", HIB"������ս����"HIW + "һ���ξ��˱����˵������������ĸ���!\n"NOR,users() );
		if(objectp(room=load_object("/d/xiangyang/eastjie1")) && 
		objectp(badguy = new("/quest/guojob/menggu/songbing")))
		badguy->move(room);
                room=load_object("/d/xiangyang/westjie1");
                badguy = new("/quest/guojob/menggu/songbing");
                badguy->move(room);
                room=load_object("/d/xiangyang/southjie1");
                badguy = new("/quest/guojob/menggu/songbing");
                badguy->move(room);
	}
        if (random(4) == 1)
        {
message("channel:chat", HIB"������ս����"HIW + "һ���ɹž���������������Ǳ��Ÿ���!\n"NOR,users() );
		if(objectp(room=load_object("/d/xiangyang/dingzi")) && 
		objectp(badguy = new("/quest/guojob/menggu/mengu2")))
		badguy->move(room);
                room=load_object("/d/xiangyang/northroad1");
                badguy = new("/quest/guojob/menggu/mengu2");
                badguy->move(room);
                room=load_object("/d/xiangyang/jiekou2");
                badguy = new("/quest/guojob/menggu/mengu2");
                badguy->move(room);
                room=load_object("/d/xiangyang/dingzi");
                badguy = new("/quest/guojob/menggu/mengu3");
                badguy->move(room);
  	}
        if (random(4) == 2)
        {
message("channel:chat", HIB"������ս����"HIW + "һ����ɹű�����������������Ÿ���!\n"NOR,users() );
		if(objectp(room=load_object("/d/xiangyang/westjie1")) && 
		objectp(badguy = new("/quest/guojob/menggu/mengu1")))
		badguy->move(room);
                room=load_object("/d/xiangyang/westjie2");
                badguy = new("/quest/guojob/menggu/mengu1");
                badguy->move(room);
                room=load_object("/d/xiangyang/juyiyuan");
                badguy = new("/quest/guojob/menggu/mengu1");
                badguy->move(room);
                room=load_object("/d/xiangyang/westjie2");
                badguy = new("/quest/guojob/menggu/mengu1");
                badguy->move(room);
                room=load_object("/d/xiangyang/westjie2");
                badguy = new("/quest/guojob/menggu/mengu1");
                badguy->move(room);
                room=load_object("/d/xiangyang/westjie2");
                badguy = new("/quest/guojob/menggu/mengu1");
                badguy->move(room);
 	}
        if (random(4) == 3)
        {
message("channel:chat", HIB"������ս����"HIW + "�м����ɹż�ϸ����������������Ÿ���!\n"NOR,users() );
		if(objectp(room=load_object("/d/xiangyang/southjie2")) && 
		objectp(badguy = new("/quest/guojob/menggu/mengu4")))
		badguy->move(room);
                room=load_object("/d/xiangyang/southjie2");
                badguy = new("/quest/guojob/menggu/mengu4");
                badguy->move(room);
	}

        return 1;

}

string ask_newover()
{
         object me;
         me = this_player();
          if(me->query_condition("jobshadi_limit")<=1)
         return "��û��������,������Ϲ����ʲ��?";
         me->clear_condition("jobshadi_limit");
         me->add("combat_exp",-100+random(20));
         me->apply_condition("jobshadi_failed",10);
         me->delete_temp("mark/job_shadi");
	 me->delete_temp("carry_location");
         me->delete_temp("job_over");
         me->delete_temp("start_job");
	 return "û��ϵ,�´μ���Ŭ�� ��";
}