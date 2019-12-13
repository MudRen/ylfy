// xingge.c �Ǹ�
// By Lgg,1998.10
// modified by wind

#include <ansi.h>
inherit NPC;
int peiqian(object me);
int do_ya(string arg);

//ȫ�̱���
int thecash;

void create()
{
	set_name("�Ǹ�", ({ "xing ge", "xing" }));
	set("gender", "����");
	set("long",
		"���Ǻųơ���ʥ�������ǳڣ����Ǹ硣\n"
	);
	set("age", 32);
	set("title",HIW"���޶���"NOR);
	set("nickname",CYN"��ʥ"NOR);

	set("immortal",1);

	set("inquiry", ([
		"���»�"   : "Ŷ�������ʻ��̰��������ҵ�ʦ�֣��˳ơ���������\n",  
		"����" : "��ʦ��������Ҳ�����Һ��õģ�\n",
	]) );	

	set("book_count",1);

	setup();

	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_ya","ya");
}

int accept_object(object who, object ob)
{
//object obj;
	object me=this_player();

	if (query("book_count")) {
    	if (ob->query("money_id")) {
		if (ob->query_temp("tmark/��")) {
			message_vision(HIG"�Ǹ����ؿ���$N˵�����Ѿ��¹�ע��ѽ��\n"NOR,who);
		}
	if (ob->value()<100) {
			message_vision(HIR"�Ǹ粻мһ�˵ؿ���$N��˵����Ҫ��ע����һ�����ӣ�\n"NOR,who);
			return 0;
			}
	if (ob->value()>2000000) {
			message_vision(HIR"�Ǹ�ҡ��ҡͷ����$N˵�������ﲻ��ӭ��עһ���������ע200���ƽ�\n"NOR,who);
			return 0;
         }
		add("book_count",-1);
		thecash = ob->value();
		who->set_temp("tmark/��",1);

		message_vision(HIY"�Ǹ�ߺ�ȵ�����ע��ɣ�����Ѻ��ѺС�Ϳ�$Nһ�仰�ˡ�\n"NOR,who);
		message_vision(HIY"��type ya da(xiao)������Ѻע��\n"NOR,who);

	        remove_call_out("destroying");
        	call_out("destroying", 0, me, ob);
		return 1;
	}
	} // if (query("book_count"))
	else {
		message("vision",HIY"�Ѿ��������Ǹ�Զ��ˣ�����$N�õ��²����ˡ�\n"NOR,who);
		return 0;
	}
}

int do_ya(string arg)
{
	object me=this_player();
	int l1,l2,l3,sum;

	if(!arg || (arg!="da" && arg!="xiao"))
		return notify_fail("�㵽��ҪѺʲô��\n");

	if (!me->query_temp("tmark/��")) {
		message_vision(MAG"�Ǹ粻�ͷ�������$Nһ�ѣ�ȥȥȥ��Ǯ��û������Ѻ��С��\n"NOR,me);
		return 1;
	}

	l1=1+random(6);
	l2=1+random(6);
	l3=1+random(6);
	sum=l1+l2+l3;

	message("vision",HIG"ֻ������ɫ�Ӳ�ͣת��������ͣ����������"+l1+" "+l2+" "+l3+"��\n"NOR,me);
	if (l1==l2 && l2==l3) {
		message_vision(HIG"�Ǹ�����е������ˣ�"+l1+" "+l2+" "+l3+" "+"��ȫһɫͨɱ��\n"NOR,me);
	}
	else {
	if(sum>10)
		message_vision(HIG"�Ǹ�����е������ˣ�"+l1+" "+l2+" "+l3+" "+"��"+sum+"��󣬳�С���\n"NOR,me);
	else
		message_vision(HIG"�Ǹ�����е������ˣ�"+l1+" "+l2+" "+l3+" "+"��"+sum+"��С���Դ���С��\n"NOR,me);
	if(sum>10) {
		if(arg=="da") {
			message("vision",HIW"�Ǹ�һ���������ŵı��飬�棬����ô��Ѻ�еģ�\n"NOR,me);
			peiqian(me);
		}
		else {
			message("vision",HIR"�Ǹ�����һЦ���������ˣ�������˼��\n"NOR,me);
		}
	}
	else {
		if(arg=="xiao") {
			message("vision",HIW"�Ǹ�һ���������ŵı��飬�棬����ô��Ѻ�еģ�\n"NOR,me);
			peiqian(me);
		}
		else {
			message("vision",HIR"�Ǹ�����һЦ���������ˣ�������˼��\n"NOR,me);
		}
	}
	} // end of else

	me->set_temp("tmark/��",0);
	set("book_count",1);
	return 1;
}

int peiqian(object me)
{
	object ob,ob1;

	if(thecash<10000) {
	ob = new("/clone/money/silver");
	ob->set_amount(thecash/100*2);
	ob->move(me);	
	}
	else {
	ob = new("/clone/money/gold");
	ob->set_amount(thecash/10000*2);
	ob->move(me);
	if((thecash % 10000)!=0) {
		ob1 = new("/clone/money/silver");
		ob1->set_amount((thecash-((thecash/10000*10000)))/100*2);
		ob1->move(me);
	}
	}
	me->set_temp("tmark/��",0);
	return 1;	
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

