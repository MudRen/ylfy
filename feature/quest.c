
/*
 * create by evilgod@xbtxii
 * Last change by rongg@xbtxIII 2001/1/15
 * �����˹��ڶ�����quest�Ľ����취
 */
#include <ansi.h>
#include <dbase.h>
int time_period(int timep, object me);

void fail_quest(object me)
{
        return;
}
void questbonus(object me)
{
        me->set("quest/fealty",1);
}

int cancel_quest(object who,object ob)
{         
        if(ob->value()>random(who->query("per")*100)+100)
        {
        	who->set_temp("quest/exp",0);
                who->set_temp("quest/pot",0);
                who->set_temp("quest/score",0);
                who->set("quest",0);
                message_vision("$N��$nһ˦���䣬˵������û�ã��ⶼ�ɲ���\n",this_object() ,who);
                return 1;
        }
        else message_vision("$N��ŭ�ȵ�����������¸ҲҪ��һ��"+
                             "���а�!���Ǯ��ʲô��˼��\n",this_object());
        return 0;
}

string * choice_quest(string tag)
{
        string *quest,ext;
        
        if(!stringp(ext=query("quest_ext"))) ext="";
                
        if(random(2)<1)
        {
            quest = ({"ɱ"});
            if(file_size("/quest/qlist"+tag+"kill"+ext+".c") >= 0)
                 quest+= ({ "/quest/qlist"+tag+"kill"+ext});
            else quest+= ({ "/quest/qlist"+tag+"kill"});
        }
        else if(random(2)==3)
        {
            quest = ({"ʤ"});
            if(file_size("/quest/qlist"+tag+"npc"+ext+".c") >= 0)
                 quest+= ({"/quest/qlist"+tag+"npc"+ext});
            else quest+= ({ "/quest/qlist"+tag+"npc"});
        }
        else 
        {
            quest = ({"Ѱ"});
            if(file_size("/quest/qlist"+tag+"obj"+ext+".c") >= 0)
                 quest+= ({"/quest/qlist"+tag+"obj"+ext});
            else quest+= ({ "/quest/qlist"+tag+"obj"});
        }
        return quest;

}
int give_quest()
{
        string quest_type;
        string quest,* quest_file;
        object me,ob;
        int j, combatexp, timep,factor,num;
        string tag = "1000000";
        string *levels = ({
                        "0",
                        "1",
                        "2",
                        "4",
                        "8",
                        "16",
                        "32",
                        "64",
                        "128",
                        "256",
                        "512",
                        "1024",
        });
        me = this_player();
        ob = this_object();
// Let's see if this player still carries an un-expired task

        if(me->query("family/family_name")!=ob->query("family/family_name"))
        {
                message_vision("$N������Ҿ,������ò�Ķ�$n˵���� ��ӭ�������٣�������ָ��! ��\n", ob,me);
                command("say �����Ͷ��������֣���������Ц��");
                return 1 ;
        }
        if((quest =  me->query("quest")))
        {
                if( ((int) me->query("task_time")) >  time() )
                       return 0;
                else
                {
                       message_vision("$N��$nһ˦���䣬˵����"
                               "��û�ã����������㻹�������ҵķ��ϣ����ڸ���һ�λ��ᣮ\n", ob,me);
                       me->set("kee", me->query("kee")/2+1);
                       me->set_temp("quest/score",0);
                       me->set_temp("quest/exp",0);
                       me->set_temp("quest/pot",0);
                }
        }
        combatexp = (int) me->query("combat_exp")/1000;

        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
//                              tag = levels[j];
                                num=j;
                                factor=10;
                                break;
                        }
        }
        if (num>0)
        {
                if (random(50+me->query_kar())>65)
                {
                        num=num-1;
                }
        }
        else 
        {
                if ((num<sizeof(levels)-1)&&(random(100)>95))
                {
                        num=num+1;
                        factor=15;
                }
        }
        tag=levels[num];
        quest_file=choice_quest(tag);
        quest_type=quest_file[0];
        quest=quest_file[1]->query_quest();
    	while (quest_type == "ɱ")
	{
		if(quest==this_object()->name()||quest==me->query("family/master_name"))
		{
        		quest_file=choice_quest(tag);
        		quest_type=quest_file[0];
                        quest=quest_file[1]->query_quest();
		}
		else
			break;
	}	        
        
        timep = random(me->query_kar()*6)+random(me->query_int()*2)
                +random(me->query_spi()*5)+random(me->query_per()*5)
                +400-random(me->query_skill("force",1));
        time_period(timep, me);
        if (quest_type == "Ѱ")
        {
                tell_object(me,"�һء�"+quest+"�����ҡ�\n" NOR);
        }
        if (quest_type == "ɱ")
        {
                tell_object(me,"����ɱ�ˡ�"+quest+"����\n" NOR);
        }
        if (quest_type == "ʤ")
        {
        	tell_object(me,"���ҽ�ѵ��"+quest+"��һ�¡�\n" NOR);
        }
        questbonus(me);
        me->set("quest/name", quest);
        me->set("quest/type", quest_type);
        me->set("task_time", (int) time()+timep);
        me->set("quest_factor",factor);
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,HIW +this_object()->name()+"��˼��һ�����˵����\n����" + time + "��");
        return 1;
}
int accept_object(object who, object ob)
{
        int exp, pot, score,factor,i;
        object me,*member;
        string quest;
        me=this_object();
        if(! who->query("quest")||!(quest =  who->query("quest")["name"])||userp(ob))
        {
                tell_object(who,me->name()+"˵�����ⲻ������Ҫ�ġ�\n");
                return 0;
        }

        //if(me->query("family/family_name")!=who->query("family/family_name"))
        //        return 0;
        if (ob->query("money_id")&&ob->name(1) != quest)
        {
                return cancel_quest(who,ob);
        }

        if( ob->name(1) != quest)
        {
                tell_object(who,me->name()+"˵�����ⲻ������Ҫ�ġ�\n");
                return 0;
        }
        if (!ob->query("money_id")) call_out("todest",3,ob);
        if ((int) who->query("task_time") < time() )
        {
                fail_quest(who);
                tell_object(who,me->name()+
                        "˵�������ϧ����û����ָ����ʱ������ɣ�\n");
                who->set_temp("quest/score",0);
                who->set_temp("quest/exp",0);
                who->set_temp("quest/pot",0);
                return 1;
        }
        else
        {
                
                exp = random(who->query_skill("parry")/4)
                      +random(who->query_skill("dodge")/4)
                      +random(40)
                      +random(who->query_skill("force")/4)+2;
                pot = random(who->query_con()/2)+random(who->query_kar()/2)+random(20)+1;
                score = random(exp+pot*2);
                factor=who->query("quest_factor");
                if (exp>120) exp= 120;
                if (exp<12) exp= 12;
                if (pot>18) pot = 18;
                if (pot<3) pot = 3;
                // zjun


		if(pointerp(member=who->query_team()))//���ڶ������quest֮���ý���
        	{				//���ڽ�ѵ��սʤ���ֵĶ��齱���μ�/adm/daemons/reward.c
                	who->set("quest", 0 );
                	for(i=0;i<sizeof(member);i++)
                	{
                        	if(member[i]->query("combat_exp")>=3000000)
                        	{//��who�Ķ�Ա����quest,��ô������Ա���Ի�õĽ���=��Ա(who)�ı��ν���
                                	member[i]->add_temp("quest/exp",exp);
                                	member[i]->add_temp("quest/pot",pot);
                                	if( member[i]->query_temp("quest/exp")> 720) 
  	                        		member[i]->set_temp("quest/exp",720);
                        		if( member[i]->query_temp("quest/pot")> 81) 
	                                	member[i]->set_temp("quest/pot",81);

        	                }
                	        else
                        	{
                                	member[i]->add_temp("quest/exp",exp);
                                	member[i]->add_temp("quest/pot",pot);
                                	if( member[i]->query_temp("quest/exp")> 1500) 
	  	                        	member[i]->set_temp("quest/exp",1500);
        	                	if( member[i]->query_temp("quest/pot")> 150) 
                	                	member[i]->set_temp("quest/pot",150);
                        	}
                		
                        	member[i]->add("combat_exp",member[i]->query_temp("quest/exp"));
                        	member[i]->add("potential",member[i]->query_temp("quest/pot"));
                        	member[i]->add("fealty",member[i]->query("quest/fealty"));
                        	//me->delete("quest");
                        	//Ϊ�˹�����ҵĺ���̬��,���ﲻɾ����Ա��������
                        	//����˵���κ�һ����Ա���quest֮��,��Ҷ������ͬ�Ľ���,�����������еĳ�Ա
                        	//ͬʱ������
	                        tell_object(member[i],"��ϲ�㣡��Ķ����������һ������\n");
        	                tell_object(member[i],HIW"�㱻�����ˣ�\n" 
                                  +chinese_number(member[i]->query_temp("quest/exp")) + "��ʵս����\n"
                                  +chinese_number(member[i]->query_temp("quest/pot")) + "��Ǳ��\n"NOR);
        	
                	}	
        		return 1;
        	}
        

		tell_object(who,me->name()+"˵����ϲ�㣡���������һ������\n");
                who->add_temp("quest/exp", exp);
                who->add_temp("quest/pot",pot);
                if(who->query("combat_exp")>=3000000)
                {
                        if( who->query_temp("quest/exp")> 720) 
  	                       who->set_temp("quest/exp",720);
                        if( who->query_temp("quest/pot")> 81) 
                               who->set_temp("quest/pot",81);
                }
                else 
                {
                        if( who->query_temp("quest/exp")> 1500) 
  	                       who->set_temp("quest/exp",1500);
                        if( who->query_temp("quest/pot")> 150) 
                               who->set_temp("quest/pot",150);
                }     
                who->add("combat_exp", (int) who->query_temp("quest/exp"));
                who->add("potential",(int) who->query_temp("quest/pot"));
                who->add_temp("quest/score",score);
                who->add("score", (int) who->query_temp("quest/score"));
                who->add("fealty",(int)who->query("quest/fealty"));
                tell_object(who,HIW"�㱻�����ˣ�\n" +
                chinese_number(who->query_temp("quest/exp")) + "��ʵս����\n"+
                chinese_number(who->query_temp("quest/pot")) + "��Ǳ��\n" +
                chinese_number(who->query("quest/fealty"))+"��ʦ���ҳ϶ȡ�\n"NOR);
                who->set("quest", 0 );
        }
        
        return 1;
}
void todest(object ob)
{
	destruct(ob);
}


