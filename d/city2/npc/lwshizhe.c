// lwshizhe.c ����ʹ��

// ������������ʶ
#define THIS_GIFT_ALL "1001_gift"
// �����ϴ������ʶ
#define LAST_GIFT_ALL "0925_gift"
// ����װ���ȼ�
#define GIST_ITEM_LEVEL 15

inherit NPC;
inherit F_MASTER;

#include <item_sx.h>

string *random_item = ({
	"/clone/map/weapon/axe",
	"/clone/map/weapon/blade",
	"/clone/map/weapon/club",
	//"/clone/map/weapon/dagger",
	//"/clone/map/weapon/fork",
	"/clone/map/weapon/hammer",
	//"/clone/map/weapon/ring",
        "/clone/map/weapon/staff",
	"/clone/map/weapon/whip",
	"/clone/map/weapon/sword",
	"/clone/map/weapon/spear",
	});

int gift_item(string str);
int ask_yuebing(string str);
int ask_qiankun(string str);

void create()
{
	set_name(HIC"��������ʹ��"NOR, ({ "gift shizhe", "shizhe" }));
	set("title", HIW"С��ʹ"NOR);
	set("nickname", HIG"������Ů"NOR);      	
	set("str", 37);
	set("gender", "Ů��");
	set("age", 14);
	set("per",30);
	set("long", "����һ���������˵�С��������۾����������޵����顣\n ��������ר�Ÿ���ҷ��ͽ������\n");
	set("combat_exp", 15000000);
	set("max_qi", 3000000);
	set("max_jing", 3000000);
	set("neili", 15000000);
	set("jiali", 50000);
	set("no_get", 1);	
	set("attitude", "friendly");
	set("inquiry", ([
		"�ƽ��Աװ��": "������ǻƽ��Ա������ͨ��ָ�� "HIM"draw weapon װ�����[0��7]"NOR
		" ��ȡһ��������װ������\n"HIW"װ�����Ͷ�Ӧ������£�\n"HIY
		"��(0)����(1)����(2)����(3)����(4)����(5)����(6)��ǹ(7)\n"NOR,
		//"����": (: ask_yuebing :),         
        "Ǭ����" : (: ask_qiankun :),		
		]));
    
	setup();
	carry_object("/clone/cloth/female1-cloth")->wear();	
}

void init()
{
	object ob;

	ob = this_player();

	if ( !ob ) return;

	add_action("gift_item", "draw");
}

int gift_item(string arg)	
{
	object me, shizhe, gift, *inv;
	string name, *item;
	int i, max, type;

	me = this_player();
	shizhe = this_object();

	if ( !me || !shizhe ) return 0;
	/*if ( me->query("xyhy_type") != 2 )
	{ // ���ǻƽ��Ա
		tell_object(me, "ֻ�лƽ��Ա������ȡװ��\n");
		return 1;
	}*/
	if ( !arg || sscanf(arg, "weapon %d", type) != 1 )
	{ // ��������ʽ
		tell_object(me, "��ȡװ�������ʽ��draw weapon װ�����[0��7]\n"
						HIW"װ�����Ͷ�Ӧ������£�\n"HIY
						"��(0)����(1)����(2)����(3)����(4)����(5)����(6)��ǹ(7)\n"NOR);
		return 1;
	}
	if ( type < 0 || type > sizeof(random_item)-1 )
	{ // ����ŷ�Χ
		tell_object(me, "��ȡװ�������ʽ��draw weapon װ�����[0��7]\n"
						HIW"װ�����Ͷ�Ӧ������£�\n"HIY
						"��(0)����(1)����(2)����(3)����(4)����(5)����(6)��ǹ(7)\n"NOR);
		return 1;
	}
	if ( sizeof(all_inventory(me)) > 50 )
	{ // ��������Ʒ����
		tell_object(me, "�����ϵĶ���̫�����޷���װ�¸������Ʒ�����������������ɣ�\n");
		return 1;
	}

	// ȡ�þ���װ��
	gift = new(random_item[type]);
	// ȡ��װ�����ܵ�����������
	item = keys(weapon_shuxing);
	max = sizeof(item);
	for ( i=0; i<max; i++ )
	{
		gift->set("weapon_prop/"+item[i], GIST_ITEM_LEVEL*100); // ���ó�������
	}
	//_______________________������������______________________
	gift->set_weight(3000 + (random(max) * 100) + (random(GIST_ITEM_LEVEL) * 100)); // ����
	gift->set("value", 5000000 + (random(max + GIST_ITEM_LEVEL) * 1000000)); // ��ֵ
	gift->set("weapon_prop/level", GIST_ITEM_LEVEL*2); // �ȼ�
	gift->set("flag", 2); // ����Ϊ��������
	gift->set("no_get", 1);
	gift->set("no_put", 1);
	gift->set("no_drop", 1);
	gift->set("no_sell", 1);
	gift->set("no_give", 1);
	gift->set("no_tie",1);
	gift->set("bind_master_level/"+me->query("id"), 1); // ���ð󶨵ȼ�
	//___________________________ END _________________________
	//________________________��������_____________________
	name = gift->name(1);
	name = filter_color(name);
	gift->set("name", MAG"����"HIY+name+"��VIP��"NOR); // ��������
	gift->set("xyzx_item/pinji", 3); // ����Ϊ��װ
	//__________________________END________________________

	if ((int)me->query_encumbrance() + gift->weight() > (int)me->query_max_encumbrance() )
	{ // ��鸺�����
		tell_object(me, "������������̫���ˣ����������������������ɣ�\n");
		destruct(gift);
		return 1;
	}
	/*if ( !wizardp(me) && me->query(THIS_GIFT_ALL) )
	{ // ÿ ID ֻ����ȡһ��
		tell_object(me, "�Բ���Ŷ��ÿ����ֻ������ȡһ�Σ����Ѿ������Ŷ��\n");
		destruct(gift);
		return 1;
	}*/
	inv = all_inventory(me);
	for ( i=0; i<sizeof(inv); i++ )
	{
		if ( inv[i]->query("bind_master_level/"+me->query("id")) 
			&& inv[i]->query("xyzx_item/pinji")==3 )
		{ // �����������ٴ���ȡ
			tell_object(me, "�Բ���Ŷ���������Ѿ���һ���ˡ�\n");
			destruct(gift);
			return 1;
		}
	}
	
	message_vision(YEL"$N���������ָ���ŵ�һ�����һ"+gift->query("unit")+gift->name(1)+"�͸���$n\n"NOR, shizhe, me);
	gift->move(me);
	//_______________________��־��ȡ��ȡ״̬________________________
	me->delete(LAST_GIFT_ALL);
	me->set(THIS_GIFT_ALL, 1);
	//_____________________________ END _____________________________
	return 1;
}

int ask_yuebing(string arg)	
{    
	object me;
	object shizhe;	
	object gift;
	
	me = this_player();
	shizhe = this_object();

	if ( !me || !shizhe ) return 0;
	if ( me->query("071001_gift") )     	
	{ // �Ѿ������
		tell_object(me, "�㲻���Ѿ���������ˣ���ô�����ã�\n");
		return 1;
	}

	message_vision(CYN "������ʹ�ó�һ������͸���$N \n" NOR, me);
	gift = new("/clone/misc/guoqi");
	gift->move(me);	      	
	me->delete("07815_gift");
	me->set("071001_gift", 1);
	return 1;
}

int ask_qiankun(string arg)	
{
	object me,obj;
	object shizhe;
	me = this_player();
	shizhe=this_object();
	if ( sizeof(all_inventory(me)) > 50 )
	{ // ��������Ʒ����
		tell_object(me, "�����ϵĶ���̫�����޷���װ�¸������Ʒ�����������������ɣ�\n");
		return 1;
	}
	if(present("qiankun dai", me))
	{
		command("say �Ѿ����˻�����,����ô���̰��������?");
		return 1;
	}
	else
	{
		message_vision(CYN "����ʹ��΢Ц���ó���Ǭ���������˸�$N \n" NOR,me);
		obj=new("/clone/misc/qiankun-dai.c");
		obj->set("xyzx_sys/bind_type", 2);
		obj->set("xyzx_save_item", 1);
		obj->move(me);
		command("love");
		return 1;
	}
}
