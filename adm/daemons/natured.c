// natured.c
#include <ansi.h>

#define TIME_TICK (time()*60)
#define TIME_TICK1 (time()*60)

nosave int current_day_phase, current_month;
mapping *day_phase;
nosave string ppl;
//���ܳ��������ĵط� by.simeng
string *box_object=({
"/d/wudang/haohan",
"/d/taishan/zhangren",//��������Լ��������
"/d/quanzhou/nanmen",
"/d/nanyang/ruzhou",
"/d/huashan/yunu",
"/d/songshan/junjigate",
"/d/taohua/qianyuan",
"/d/tongchi/damen",
"/d/wudujiao/damen",
"/d/xiaoyao/qingcaop",
"/d/taishan/tanhai",

});
string *month_desc = ({
	HIW"¡����"NOR,
	HIW"������"NOR,
	HIG"������"NOR,
	HIG"�紺���µ�"NOR,
	HIG"�������µ�"NOR,
	HIC"���ĵ�"NOR,
	HIC"ʢ�ĵ�"NOR,
	HIR"���ĵ�"NOR,
	HIY"�����"NOR,
	HIY"�����ˬ��"NOR,
	YEL"�����"NOR,
	WHT"������"NOR,
});

mapping *read_table(string file);
void init_day_phase();

void create()
{
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
        get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "��":
		case "ʮ":
		case "ʮһ":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		case "һ":
		        if(get_day=="һ")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		        
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;
	
	local = localtime(TIME_TICK1);
	t = local[2] * 60 + local[1];      


	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_month = local[4];

	remove_call_out("init_day_phase");
	call_out("init_day_phase", 3600);
	remove_call_out("update_day_phase");
	call_out("update_day_phase", (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
        remove_call_out("update_day_phase");

        current_day_phase = (++current_day_phase) % sizeof(day_phase);
switch (day_phase[current_day_phase]["outcolor"])	
        {
              case "BLK":
message("channel:chat", HIW"��"HIM"��ã���     "BLK + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());//"channel:chat"	
                   break;
              case "RED":
message("channel:chat", HIW"��"HIM"��ã���     "RED + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "HIR":
message("channel:chat", HIW"��"HIM"��ã���     "HIR + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "GRN":
message("channel:chat", HIW"��"HIM"��ã���     "GRN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "HIG":
message("channel:chat", HIW"��"HIM"��ã���     "HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "YEL":
message("channel:chat", HIW"��"HIM"��ã���     "YEL + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "HIY":
message("channel:chat", HIW"��"HIM"��ã���     "HIY + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "BLU":
message("channel:chat", HIW"��"HIM"��ã���     "BLU + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "HIB":
message("channel:chat", HIW"��"HIM"��ã���     "HIB + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "MAG":
message("channel:chat", HIW"��"HIM"��ã���     "MAG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "HIM":
message("channel:chat", HIW"��"HIM"��ã���     "HIM + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "CYN":
message("channel:chat", HIW"��"HIM"��ã���     "CYN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "HIC":
message("channel:chat", HIW"��"HIM"��ã���     "HIC + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "WHT":
message("channel:chat", HIW"��"HIM"��ã���     "WHT + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              case "HIW":
message("channel:chat", HIW"��"HIM"��ã���     "HIW + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
              default:
message("channel:chat", HIW"��"HIM"��ã���     "HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());	
                   break;
        }
//        message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
        if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
            call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

        call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}
void event_morning()
{
	object badguy;
	object room;
        if (random(12) == 1)
        {
		if(objectp(room=load_object("/d/city/guangchang")) && objectp(badguy = new("/quest/weiguo/japan/japan4")))
		        badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIY"����͢������"HIR + "�����ݳ��з����ձ���ϸ��\n"NOR,users() );
	}
        if (random(12) == 2)
        {
		if(objectp(room=load_object("/d/city2/di_anmen")) && objectp(badguy = new("/quest/weiguo/japan/japan4")))
		        badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIY"����͢������"HIM + "�ڱ������з����ձ���ϸ��\n"NOR,users() );
	}
        if (random(12) == 3)
        {
		if(objectp(room=load_object("/d/city3/guangchang")) && objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
 message("channel:chat", HIY"����͢������"HIM + "�ڳɶ����з����ձ���ϸ��\n"NOR,users() );
	}
        if (random(12) == 4)
        {
if(objectp(room=load_object("/d/wanjiegu/road1")) && objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
message("channel:chat", HIB"����͢������"GRN + "�ڴ�����з��ֽ����ϸ��\n"NOR,users() );
	}
        if (random(12) == 5)
        {
if(objectp(room=load_object("/d/tianlongsi/dadao1")) && objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
message("channel:chat", HIG"����͢������"CYN + "�ڴ�����з����ɹż�ϸ��\n"NOR,users() );	
	}
        if (random(12) == 6)
        {
if(objectp(room=load_object("/d/city/nanmen")) && objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
message("channel:chat", HIG"����͢������"CYN + "�����ݳ����з����ɹż�ϸ��\n"NOR,users() );	
	}
        if (random(12) == 7)
        {
if(objectp(room=load_object("/d/city2/dongmen")) && objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
message("channel:chat", HIG"����͢������"CYN + "�ڱ��������з����ɹż�ϸ��\n"NOR,users() );	
	}
        if (random(12) == 8)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) && objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
  message("channel:chat", HIR"����͢������"BLU + "��Ȫ�ݳ��з������ļ�ϸ��\n"NOR,users() );
	}
        if (random(12) == 9)
        {
		if(objectp(room=load_object("/d/dali/xidajie3")) && objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
message("channel:chat", HIR"����͢������"BLU + "�ڴ�����з������ļ�ϸ��\n"NOR,users() );	
	}
        if (random(16) == 1)
        {
		if(objectp(room=load_object("/d/city3/westchengmen")) && objectp(badguy = new("/quest/weiguo/xixiabing/xixia3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
message("channel:chat", HIR"��ǰ�߸漱��"HIW + "���Ĵ�����������ľ�������ɶ���\n"NOR,users() );	
	}
        if (random(16) == 2)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) && objectp(badguy = new("/quest/weiguo/japan/japan3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
  message("channel:chat", HIR"��ǰ�߸漱��"HIW + "���ܴ����Ȫ�ݸ�����½��ɱ�Ұ���!!\n"NOR,users() );
	}
        if (random(16) == 4)
        {
		if(objectp(room=load_object("/d/city/ximen")) && objectp(badguy = new("/quest/weiguo/menggu/mengu3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
message("channel:chat", HIR"��ǰ�߸漱��"HIW + "�ɹŴ���������������ݣ����ݸ漱!!\n"NOR,users() );	
	}
        if (random(16) == 7)
        {
		if(objectp(room=load_object("/d/city2/di_anmen")) && objectp(badguy = new("/quest/weiguo/jinbing/jin3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
  message("channel:chat", HIR"��ǰ�߸漱��"HIW + "��������ϵĲ���ɱ���˾��ǣ����Ǹ�Σ!!\n"NOR,users() );
	}
}
void event_night()
{
	int rand;
	string newroom;
	object badguy;
	object room;
	//����ص����������
	rand=random(sizeof(box_object));
	newroom=box_object[rand];
	room=load_object(newroom);
        if (room && random(30)==1 )//random���������Կ���ʱ��ĳ��� Ĭ�Ͽ�������Ϊ24
	{
		room->set("����/liuxing",1);
		if (random(2)==1)
		message("channel:chat",HIM"�����ԡ�ĳ�ˣ���˵"+room->query("short")+HIM"�����ո����˳������꣡\n"NOR,users());
		else
		message("channel:chat",HIM"�����ԡ�ĳ�ˣ���˵��������"+room->query("short")+HIM"����׹�䣡\n"NOR,users());
		
		message("vision",HIY"������ƺ������ǻ�������\n"NOR, room);
		call_out("del", 600, room);
	}
	
        if (random(10) == 1)
        {
		if(objectp(room=load_object("/d/city/guangchang")) && objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(10) == 2)
        {
		if(objectp(room=load_object("/d/city2/di_anmen")) && objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(10) == 3)
        {
       if(objectp(room=load_object("/d/changan/ca28")) && objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(10) == 4)
        {
       if(objectp(room=load_object("/d/tianlongsi/dadao4")) && objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
   message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(10) == 5)
        {
       if(objectp(room=load_object("/d/changan/ca16")) && objectp(badguy = new("/quest/feizei/yinzei")))
		badguy->move(room);
   message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�������н�ҹ���������У������������Ų�������Ī����\n"NOR,users() );	
	}
        if (random(10) == 6)
        {
      if(objectp(room=load_object("/d/dali/guangchang")) && objectp(badguy = new("/quest/feizei/yinzei")))
		badguy->move(room);
    message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "������н�ҹ���������У������������Ų�������Ī����\n"NOR,users() );	
	}
        if (random(10) == 7)
        {
      if(objectp(room=load_object("/d/city3/guangchang")) && objectp(badguy = new("/quest/feizei/yinzei")))
		badguy->move(room);
    message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�ɶ����н�ҹ���������У������������Ų�������Ī����\n"NOR,users() );	
	}
        if (random(10) == 8)
        {
      if(objectp(room=load_object("/d/changan/ca")) && objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
    message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );	
	}
        if (random(10) == 9)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) && objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
    message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "Ȫ�ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(10) == 10)
        {
    if(objectp(room=load_object("/d/city/nandajie1")) && objectp(badguy = new("/quest/feizei/yinzei")))
		badguy->move(room);
    message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ���������У������������Ų�������Ī����\n"NOR,users() );	
	}
}

void del(object room)
{
	message("vision","�����ƺ��Ѿ�������ʲô����׹����ĺۼ��ˡ�\n", room);
	room->delete("����/liuxing");
}

void event_afternoon()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/weiguo/japan/japan1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}
void event_dawn()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/feizei/feizei");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$NЦ���������ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/feizei/yinzei");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$NЦ���������ˣ�����û�ˣ��Ͻ����ˣ�\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}
void event_midnight()
{       
	
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
	get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "��":
		case "ʮ":
		case "ʮһ":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     
		     case "һ":
		        if(get_day=="һ")
		      { day_phase = read_table("/adm/etc/nature/spring");
		     break;
			 }
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


}
        

void event_noon()
{
	object *ob;
	int i, con, con1, con2, con3;
	string get_month,ill,msg;
	mixed *local;
	local = localtime(TIME_TICK1);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		case "��":
		case "��":
		case "��":
		     ill = "ill_kesou";
		     msg = "��Ȼ��ͷһ���������о��ƺ�Ҫ�����ˡ�\n" ;
		     break;
		case "��":
		case "��":
		case "��":
		     ill = "ill_zhongshu";
		     msg = "ͻȻ������֮��һ���ڣ��������ˡ�\n" ;
		     break;
		case "��":
		case "ʮ":
		case "ʮһ":
		     ill = "ill_shanghan";
		     msg = "��������˸���ս��ͷ������ģ�����˺����ˡ�\n";
		     break;
		case "ʮ��":
		case "һ":
		case "��":
		     ill = "ill_dongshang";
		     msg = "��֫��ĩ��һ��ֱ�������㱻�����ˡ�\n";
		     break;
	}
	if(random(2))
	{
		ill = "ill_fashao";msg = HIG+"��ż�з纮����������������\n";
	}
	ob = users();
	for(i=0; i<sizeof(ob); i++)
	{
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( ob[i]->query("age")==14 ) continue;
		con1 = ob[i]->query("qi");
		con2 = ob[i]->query("max_qi");
		(int)con = con1/con2*50;
		con3 = ob[i]->query("neili");
		con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
		(int)con1 = con3/con2*50;
		if(random(con)+random(50)+random(con1)<25)
		{
			ob[i]->apply_condition(ill, 10);
			tell_object(ob[i], msg);
		}
	}
}
string outdoor_room_description()
{
	return "    " + sprintf(
		day_phase[current_day_phase]["desc_msg"],
		month_desc[current_month]) + "��\n";
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

int auto_shutdown(int flag)
{
    reclaim_objects();
    if (172800-uptime()<=0 || flag){
        message("vision", RED "Ҫ�����ˣ����ģ����ĵ����Ѿ��Զ��洢�ˣ�\n" NOR, users());
        users()->disable_player("����������......");
             call_out("backup",1);
    }
}


int backup()
{
    reset_eval_cost();
    foreach (object userob in children(USER_OB) )
	{
       if (!userob || !environment(userob))
		   continue;

       userob->save();
    }
        shutdown(0);
        return 1;

}

int xyzx_ylfy_shutdown(int v)
{
	if ( v > 0 )
		v = 0;
	else if ( v < -1 )
		v = -1;
	
	shutdown(v);
	
	return 1;
}

mapping *query_day_phase() { return day_phase; }
