// wukill 

// CLEAN_UP_TIMES ���������������
#define CLEAN_UP_TIMES 300

#include <ansi.h>;

inherit NPC;

#include "/quest/name.h";
#include "/quest/location.h";

mapping userskills;
string username;

int give_quests();
int accountguaiexp(int turn,object who);
int guaif(int turn,object who);
int guaim(int turn,object who);
int set_guai_qi_jing(int turn,object guai);
int getexp(int turn,int level,object who);
string setguaititle(int number,object guaiob);
string randomlocation(int i1);
object load_guai_place(string file_dir);

void create()
{
	
	set_name("����¥", ({ "wu zhonglou", "wu","lou" }));
	set("title", HIR"ɱ��¥��"NOR);
	set("long", "����ɱ��¥������¥����˵һ����Ϊ�Ѿ��ﵽ����ľ���,�㿴������տȻ���� ������������Ȼ�Ѿ����˺�һ�����ӹ����ˡ�\n");
	set("gender", "����");
	set("age", 800);
	set("attitude", "friendly");
	set_temp("username","fyue");
	
    set("no_suck",1);
	set("per", 100);
	set("str", 3000);
	set("int", 40);
	set("dex",500);
	set("con",500);
	set("no_accept", 1);
    set("max_qi", 30000000);
	set("max_jing", 3000000);
	set("neili", 88888888);
	set("max_neili", 40000000);
	set("max_jingli", 4000);
	set("jingli", 800000);
	set("jiali", 800000);
	set("xyzx_sys/level", 4000000);
	set("combat_exp", 50000000);
	set_skill("unarmed", 1000);
	set_skill("dodge", 1000);
	set_skill("sword", 300);
	set_skill("blade", 300);
	set_skill("parry", 300);
	set_skill("force", 300);
	set_skill("zixia-shengong", 450);
	set_skill("anranxiaohun-zhang", 1000);
	set_skill("fanliangyi-dao", 480);
	set_skill("huashan-jianfa", 400);
	set_skill("xianglong-zhang", 470);
	set_skill("dugu-jiujian", 400);
	set_skill("huashan-shenfa",460);
	set_skill("literate", 200);
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "dugu-jiujian");
	map_skill("sword", "dugu-jiujian");
	map_skill("blade", "fanliangyi-dao");
	map_skill("unarmed", "anranxiaohun-zhang");
	set("inquiry",([ 
		"kill":(:give_quests():),
		"����":"�⳥����10���ƽ��һ����Կ��ǿ��ǡ�\n",
		]));
	set("chat_chance", 10);
	set("chat_msg", ({
		"����¥̧ͷ������һ�ۣ�¶��һ������Ī�������\n",
		"����¥��̾һ����������Ҳ�������˼ǵ����ˣ���\n",
		(: command("sigh") :),
		(: command("unwield dao"):),
		(: command("unwield jian"):),
		(: command("wield dao"):),
		(: command("wield jian"):),
		(: command("exercise 100"):),
		}) );
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: exert_function, "recover" :),
		(: exert_function, "refresh" :),
		}) );
	
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/gaochang/obj/feituoarmor")->wear();
}

void init()
{
	object who;

	::init();

	if ( interactive(who = this_player()) && !who->is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, who);
	}
}

void greeting(object who)
{
	if( !who || environment(who) != environment() ) return;
	if ( (int)who->query("combat_exp") < 1000 )
	{
		switch(random(3))
		{
			case 0:command("hi "+(string)who->query("id"));break;
			case 1:command("welcome "+(string)who->query("id"));break;
			case 2:command("bow "+(string)who->query("id"));break;
			case 3:command("whisper "+(string)who->query("id")+" Ҫ������? ���Ҵ���kill����Ϣ�Ϳ�����!");break;
		}
     
	}
	else
		say("����¥��"+who->query("name")+"˵��:��λ"+RANK_D->query_respect(who)+",����������\n");
	if ( random(40) > 20 )
		command("heihei "+(string)who->query("id"));
	return;
}

// ȡ�ü���ƽ���ȼ�
int max_skill_level(object ob)
{  
	int s, i, maxlevel;
	string *str;
	
	userskills = ob->query_skills();
	if ( !mapp(userskills) ) 
	{
		maxlevel=3;
		return maxlevel;
	}
	str = keys(userskills);
	s = sizeof(str);
	if ( !s )
	{
		maxlevel=3;
		return maxlevel;
	}
	maxlevel = 0;
	for ( i=0; i<s; i++ )
	{
		maxlevel += userskills[str[i]];
	}
	maxlevel /= s;
	/*while ( s>0 )
	{
		s -= 1;
		i = userskills[str[s]];
		if (i>maxlevel) maxlevel=i;
	}*/
	return maxlevel;
}

int accountlevel(int turn,object ob)
{
	int level;
	
	level = max_skill_level(ob);
	level=(int)level*(70+turn*10)/100;
	return level;
}

string randomlocation(int i1)
{
   string *str1,*str2,loca;
   int i2,temp;
   str1=keys(allloca);
   str2=allloca[str1[i1]];
   i2=sizeof(str2);
   temp=random(i2);
   if (temp==0 || temp==i2) temp=1;
   loca=str2[0]+str2[temp];
   return loca;
}
      
int give_quests()
{
	object guaiob;
	object me,who,tempob;
	int chooseguai,rewardpot,rewardexp,turn;
	int giveuptime,guailevel;
	int temp,i1;
	string *strtemp, locastr, exit;

	me=this_object();
	who=this_player();

	giveuptime=who->query_temp("questtime2");
	//questbusytime=who->query_temp("questtime1");
	turn=who->query_temp("turn");
	if ( who->query_temp("kill") )
	{
		if ( time() < giveuptime )
        {      
			message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who) 
				+ "���Ϸ�������ȥɱ��"+who->query_temp("guainame")+"��\n", me, who);
			return 1;
		}
        else 
			turn -= 2;
	}
	/*else
	{
		if ( time() < questbusytime )
		{
			message_vision ("$N���˿���,���΢Ц�Ķ�$n˵����\n" 
				+ "��λ"+RANK_D->query_respect(who)+",�����Ѿ�������������ȥЪϢ��\n", me, who);
			return 1;
		}
	}*/
	//ÿʮ������һ�֣���turn ������
   if ( !turn || turn>9 || turn<0) 
	{
		who->set_temp("turn",0);
		turn=0;
	}
	turn = turn+1;
	guailevel=accountlevel(turn, who);
	guaiob=new("/quest/questguai");
	guaiob->set_heart_beat(1);
	guaiob->set("clean_up_times", CLEAN_UP_TIMES); // CLEAN_UP_TIMES ���������������
	guaiob->set_temp("killername", (string)who->query("id"));
	//���ùֵ�jingli,neili,exp,
	guaiob->set("max_neili",guaif(turn,who));
	guaiob->set("neili",(int)(guaif(turn,who)*2));
	guaiob->set("jiali",(int)(guaif(turn,who)/800));
	guaiob->set("max_jingli",guaim(turn,who)*3);
	guaiob->set("jingli",(int)(guaim(turn,who)*3));
	guaiob->set("combat_exp",accountguaiexp(turn,who));
	guaiob->set("neili_factor",(int)(guailevel/2));
	guaiob->set("jingli_factor",(int)(guailevel/2));
	set_guai_qi_jing(turn,guaiob);
	// ���ù���ȼ�������
	guaiob->set("xyzx_sys/level", who->query("xyzx_sys/level", 1));
	/*guaiob->set("xyzx_sys/jingzhun", who->query("xyzx_sys/jingzhun", 1));
	guaiob->set("xyzx_sys/minjie", who->query("xyzx_sys/minjie", 1));
	guaiob->set("xyzx_sys/lingxing", who->query("xyzx_sys/lingxing", 1));
	guaiob->set("xyzx_sys/fanying", who->query("xyzx_sys/fanying", 1));*/
	//set guai's "long" and "title" 
	switch (random(3))
	{
		case 1 :
			guaiob->set("long","��������"+guaiob->query("name") + ",��˵�������ɵĸ��֣�����Щ���졣\n");
			break;
		case 2 :
			guaiob->set("long","�ڵ�����"+guaiob->query("name") + "��ȫ��ɢ����һ˿а����\n");
			break;
		default :
			guaiob->set("long","�䵱��ͽ"+guaiob->query("name") + "������������ɱ�����ˡ�\n");
	}
	chooseguai=random(7);
	setguaititle(chooseguai,guaiob);
	//rewardexp and rewardpot ��ɱ�ֺ�õ���qn and exp
	rewardexp=getexp(turn,guailevel,who);
	rewardpot=rewardexp/6; 
	guaiob->set_temp("killrewardpot",rewardpot);
	guaiob->set_temp("killrewardexp",rewardexp);
	guaiob->set_temp("player",who);
	guaiob->setguaiskill(chooseguai,guailevel,guaiob);
	// guaiob->check_time(); ��������������
	//ȷ���ֵ�λ�� 
	strtemp = keys(guai_place);
	i1 = sizeof(strtemp);
	temp = random(i1);
	locastr = guai_place[strtemp[temp]];
	tempob = load_guai_place(guai_place[strtemp[temp]]); // ����bin�ļ�����������
	if ( objectp(tempob) )
	{
		exit = tempob->query("exits"); // �������
		if ( !tempob->query("short") 
			|| !mapp(exit) 
			|| !sizeof(exit) ) // ���ǵ�ͼ�ļ�����û�г��ڵĵ�ͼ��������ˢ��
			destruct(tempob);
	}
	//-------------------------
	//û��Ҫ��bin�ļ���������ķ�ʽ��ȡˢ��λ�ã�һ��ͻ��汾��bin���еģ��������Ҳ���bin�ļ�������
	if ( !objectp(tempob) ) 
	{
		strtemp=keys(allloca);
		i1=sizeof(strtemp);
		temp=random(i1);
		if (temp==i1) temp=0;
		locastr=randomlocation(temp);  
		tempob=load_object(locastr);
	}
	//if we get a wrong path,these can help us 
	if ( !objectp(tempob) )
	{
		message_vision(HIR"$N���ֺ�����ʲô�ط����Ծ��ˣ�����" + 
			"��˵��������\nwrong room :"+locastr+"\n"NOR,who);
		return 1;
	}
	guaiob->move(tempob);
	//������ҵ���ʱ����
	//who->set_temp("questtime1",time()+50);
	who->set_temp("questtime2",time()+300);
	who->set_temp("guainame",guaiob->query("name"));
	who->set_temp("turn",turn);
	who->set_temp("kill",1);
	who->set_temp("wukill_ob", guaiob); // �����ڷ�������ʱ������������
	message_vision("$N������Ц�˼�������$n˵����" + 
		RANK_D->query_respect(who) + "����ͬ�����ˣ�����һ��������ȥ���\n", me, who);
	message_vision("$N��$n˵��������" + HIY + "" + guaiob->query("name") 
		//+ "("+capitalize(guaiob->query("id"))+")" + NOR + "��" + HIG + strtemp[temp] + HIC 
		+ "("+guaiob->query("id")+")" + NOR + "��" + HIG + strtemp[temp] + HIC 
		+ "(" + tempob->query("short") + ")"NOR + "����¥���ԣ���׳ʿȥɱ������\n",me,who); 
	return 1;
}
// accountguaiexp ����ֵľ���ֵ
int accountguaiexp(int turn,object who)
{ 
	int userexp,guaiexp;
	userexp=who->query("combat_exp");
	guaiexp=userexp;
	return guaiexp;
}
// guaif ����ֵ�����
int guaif(int turn,object who)
{
	int userneili,guaineili;
	who=this_player();
	userneili=who->query("max_neili");
	guaineili=userneili*(70+turn*5)/80;
	return guaineili;
}

int guaim(int turn,object who)
{
	int userjingli,guaijingli; 
	userjingli=who->query("max_jingli");
	guaijingli=userjingli*(70+turn*5)/80;
	return guaijingli;
}

int set_guai_qi_jing(int turn,object guai)
{
	int maxqi,maxjing;
	maxqi=200+(int)guai->query("max_neili")/3*(100+turn*20)/200;
	maxjing=200+(int)guai->query("max_jingli")/3*(100+turn*8)*4/1000;
	guai->set_temp("maxqi",maxqi);
	if ( maxqi < 50000 ) maxqi = 50000;
	if ( maxjing < 25000 ) maxjing = 25000;
	guai->set("max_qi",maxqi);
	guai->set("eff_qi",maxqi);
	guai->set("qi",maxqi);
	guai->set("max_jing",maxjing);
	guai->set("eff_jing",maxjing);
	guai->set("jing",maxjing);
	return 1;
}
//ɱ�ֵõ���exp,����ҵ�skills ,exp,turn �й�
int getexp(int turn,int level,object who)
{
   int exp, my_level;

   my_level = who->query("xyzx_sys/level", 1);

  /* exp = ((level*(turn+1)>15000)?(random(15000)+5000):(level*(turn+1)))
	   + random(3000) + 1000 
	   + (random(my_level)*random(100)>15000)?(random(15000)+5000):(random(my_level)*random(100));*/
    
	//if(my_level>21000) my_level=21000;
	exp = my_level*(100+random(100));    //����һ���ſ�����20������6��ɱһ������
    if(my_level<=1000) exp *= 5;
   return exp;
}

string setguaititle(int number,object guaiob)
{
	if (random(10)>7)
	{
		if (guaiob->query("combat_exp")>2000000)
			guaiob->set("title","ɱ�˿�ħ");
		else if (guaiob->query("combat_exp")>1000000)
			guaiob->set("title","�����ӯ");
		else if (guaiob->query("combat_exp")>500000)
			guaiob->set("title","������");
		else if (guaiob->query("combat_exp")>100000)
			guaiob->set("title","���");
		else if (guaiob->query("combat_exp")>50000)
			guaiob->set("title","�ɻ���");     
		else if (guaiob->query("combat_exp")>10000)
			guaiob->set("title","��åͷ");  
		else if (guaiob->query("combat_exp")>5000)
			guaiob->set("title","��å");
		else  guaiob->set("title","С��å");
	}
	else 
	{
		switch (number)
		{
			case 1 :guaiob->set("title","ħͷ");break;
			case 2 :guaiob->set("title","���");break;
			case 3 :guaiob->set("title","��ɮ");break;
			case 4 :guaiob->set("title","��Ʀ");break;
			case 5 :guaiob->set("title","����");break;
			case 6 :guaiob->set("title","��ħ");break;
			default :guaiob->set("title","С��");break;
		}
	}
}

int accept_object(object me, object obj)
{
	object guai;

	if ( obj->query("money_id") && obj->value() >= 100000 )
	{
		command("say �ðɣ�"+me->name()+"���ϴε���������ˣ�");
		me->delete_temp("questtime1");
		//me->delete_temp("questtime2");
		me->delete_temp("kill");
		me->delete_temp("turn");
		if ( objectp(guai=me->query_temp("wukill_ob")) )
		{   // ������������
			message_vision(MAG"$N�ۼ����������һ�������ˡ�\n"NOR, guai);
			destruct(guai);
			me->delete_temp("wukill_ob");
		}
		return 1;
	}
	else
		command("say ...ι....ι...��"+me->name()+"��Ҫ������Т�������˼�Ҳ���ó�����������а���");
	return 0;
}

object load_guai_place(string file_dir)
{
	string *file, bin_dir;
	int max, get_an;

	bin_dir = "/binaries" + file_dir;
	// û�����Ŀ¼
	if ( file_size(bin_dir) != -2 ) return 0;
	// ȡ��Ŀ¼�µ��ļ���Ϣ
	file = get_dir(bin_dir, -1);
	// Ŀ¼��û���ļ�
	if ( !(max = sizeof(file)) ) return 0;
	// �����ȡ����һ���ļ�
	get_an = random(max);
	// �ļ��Ƿ���Ч
	if ( file_size(bin_dir + file[get_an][0]) <= 0 ) return 0;
	// ������ļ���һ��ֻ������ȷ�����c�ļ��Ż����bin�ļ���
	return load_object((file_dir + file[get_an][0])[0..<3]);
}