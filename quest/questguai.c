#include <ansi.h>;
inherit "/quest/npcskill";
#include <command.h>;
#include "/quest/name.h";

//1,moon,2,fangcun,3,putuo,4,hell,5,longgong,6,xueshan
//7,wudidong

object me=this_object(),questob,killertemp;
string username;
string guaiobname,*guaikeysa,*guaikeysb,*guaiobid;
int s1,s2;

void create()
{
   object guai;
   string *names1, *names2;
   string name1, name2, name3;
   string id1, id2, id3;
   int v1, v2, v3;

   names1 = keys(guai_name1);
   names2 = keys(guai_name2);
   v1 = random(sizeof(names1));
   name1 = names1[v1];
   id1 = guai_name1[name1];
   v2 = random(sizeof(names2));
   name2 = names2[v2];
   id2 = guai_name2[name2];
   if ( random(100) < 30 )
   {
	   v3 = random(sizeof(names2));
       name3 = names2[v3];
       id3 = guai_name2[name3];
   }
   else
   {
	   name3 = "";
	   id3 = "";
   }
   
   guai=this_object();

//���³������ֵ�����
   guaikeysa=keys(guainame);
   s1=random(sizeof(guaikeysa));
   if (s1==0 || s1==sizeof(guaikeysa)) s1=0; 
   guaikeysb=keys(guainame[guaikeysa[s1]]);
   s2=random(sizeof(guaikeysb));
   if (s2==0 || s2==sizeof(guaikeysa)) s2=0;
   guaiobname=guaikeysb[s2];
   guaiobid=guainame[guaikeysa[s1]][guaikeysb[s2]];
   if ( random(100) < 3 ) set_name(guaiobname,guaiobid);
   else set_name(name1+name2+name3, ({ id1+" "+id2+id3 }));

//�����������,

   set("gender","����");
   set("env/wimpy", 30);
   set("per",10);
   set("age",60);
   set("attitude", "friendly");
   set("no_suck",1);
   set_temp("apply/armor",600);
   set("chat_chance",10);
   set("chat_msg",({
   (:random_move:)}));
   set("chat_chance_combat",random(90));
   setup();
   
}
int setguaiskill(int chooseguai,int level,object guai)
{  
   set_std_skills(level,guai);
   switch (chooseguai)
    {
      case 1:set_moon_guai(level,guai);carry_moon_weapon();break;
      case 2:set_fangcun_guai(level,guai);carry_fangcun_weapon();break;
      case 3:set_putuo_guai(level,guai);carry_putuo_weapon();break;
      case 4:set_hell_guai(level,guai);carry_hell_weapon();break;
      case 5:set_longgong_guai(level,guai);carry_longgong_weapon();break;
      case 6:set_xueshan_guai(level,guai);carry_xueshan_weapon();break;
      default:set_wudidong_guai(level,guai);carry_wudidong_weapon();break;
    }
}

// ����������õ������
void heart_beat()
{
	int times;

	times = this_object()->query("clean_up_times");
	times--;

	if ( times < 1 )
	{
		if ( !me->is_fighting() )
		{
			message_vision(MAG"$N�ۼ����������һ�������ˡ�\n"NOR, this_object());
			destruct(this_object());
			return;
		}
	}

	this_object()->set("clean_up_times", times);
	::heart_beat();
}

void die ()
{
    int pot, exp, i;
    object killerob, me, baoshi;
    mixed questob;
	string username;
    me=this_object();
    
	killerob = me->query_temp("last_damage_from");                
    questob = me->query_temp("player");
	if ( !objectp(questob) )
	{
		username=me->query_temp("killername");
		questob = find_player(username);
	}
	if ( !objectp(questob) )
	{
		//remove_call_out("check_time");
		message_vision("$N�ҽ�һ�������ˡ�\n",this_object());
		destruct(me);
		return;
	}
	if ( !environment(questob) )
	{
		//remove_call_out("check_time");
		message_vision("$N�ҽ�һ�������ˡ�\n",this_object());
		destruct(me);
		return;
	}
	questob->delete_temp("kill");
	if ( !objectp(killerob) )
	{
		//remove_call_out("check_time");
		message_vision("$N�ҽ�һ�������ˡ�\n",this_object());
		tell_object(questob, "��õ�����㾭������Ǳ�ܣ�\n"NOR);
		destruct(me);
		return;
	}
	if ( killerob != questob )
	{
		//remove_call_out("check_time");
		message_vision("$N�ҽ�һ�������ˡ�\n",this_object());
		tell_object(questob, "��õ�����㾭������Ǳ�ܣ�\n"NOR);
		destruct(me);
		return;
	}
	if ( killertemp )
	{
		if ( killertemp != killerob )
		{
			//remove_call_out("check_time");
			message_vision("$N�ҽ�һ�������ˡ�\n",this_object());
			tell_object(questob, "��õ�����㾭������Ǳ�ܣ�\n"NOR);
			destruct(me);
			return;
		}
	}
	//remove_call_out("check_time");
	message_vision("$N�ҽ�һ�������ˡ�\n",this_object());
	pot=me->query_temp("killrewardpot")/3;
    exp=me->query_temp("killrewardexp");
	i = 100+random(500);
    questob->add("potential",pot);
    questob->add("combat_exp",exp);
    tell_object(questob,"��õ���"+HIW+ chinese_number(exp*questob->query_exp_times())+NOR"�㾭���"+HIW+chinese_number(pot)+NOR"��Ǳ��\n");
	if (questob->query_temp("turn") ==9){
		if ( random(5) == 0 ){
		baoshi = new("/clone/map/obj/hanyu-jingtie");
		tell_object(questob, "������һ"+baoshi->query("unit")+baoshi->name(1)+NOR"��\n");	
		baoshi->move(questob);
		}
		questob->add("score",i);
	    tell_object(questob, sprintf(YEL"��������������%s�㣡\n"NOR, chinese_number(i)) );
	}
    destruct(me);
   
}
//�����ñ��˰�æ���ι�   
void unconcious()
{
	killertemp = query_temp("last_damage_from");
	::unconcious();
}

void init()
{
    if ( is_busy() ) return;
    add_action("do_drive","drive");
    username=query_temp("killername");
    if ((int)environment(me)->query("no_fight")) return; 
    if (this_player()->query("id")==username)
	{ 
		if (query_temp("firstsee")==0||!query_temp("firstsee"))
		{
			if(random(40)>20)
			{     
				message_vision(HIR"$N��ݺݵض���$n�����һ������Ȼ���������ˣ����첻����������������\n"NOR ,this_object(),this_player());
				this_object()->kill_ob(this_player());  
				command("follow "+this_player()->query("id"));
			}
			else 
				this_object()->command("? "+this_player()->query("id"));
			set_temp("firstsee",1);
          
		}
		set_heart_beat(1);
		if(random(40)<20) this_object()->kill_ob(this_player());
	}   
}

int do_drive(string arg)
{
    mapping exits;
    string *dirs;
    int size;
    if ( arg==(string)this_object()->query("id") )
	{
		if ( environment()->query("no_fight") )
		{
			exits=environment()->query("exits");      
			dirs=keys(exits);
			size=sizeof(dirs);
			if ( size>0 )
			{ 
				this_player()->command("follow "+this_object()->query("id"));
				command("go "+dirs[random(size)]);
				return 1;
			}
		}
		tell_object(this_player(), this_object()->name()+"���ڲ��ڲ���ս���ĵط�������Ҫ���ϡ�\n");
	}
	else
		tell_object(this_player(), "��Ҫ����ʲô��\n");
	return 1;
}
