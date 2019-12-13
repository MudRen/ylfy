// m_jia.c

#include <ansi.h>
#include <armor.h>
inherit S_ROBE;

int duanlian(object weapon);
int do_hui(object weapon);
int do_jianame(string arg);

//   string query_autoload() { return 1 + ""; }      //autoload weapon	:
void init()
{
	//add_action("do_duanlian1","duanlian1");
	add_action("do_hui1","hui1");
	add_action("do_levelup","jijia");
	add_action("do_jianame","jianame");
}


void create()
{
	object me;
	string w_name,w_id,w_or;
	int w_lv;

	me = this_player();
	//��������
	//w_name=me->query("jia/name");
	//w_id = "my "+me->query("jia/id");
	//w_or = me->query("jia/or");
	//w_lv = me->query("jia/lv");
	if ( !objectp(me) )
	{
		w_name="���Ƶļ���";
		w_id="my jia";
		w_or="ǧ����ľ";
		w_lv=1;
	}
	else
	{
		if ( !stringp(w_name=me->query("jia/name")) ) w_name="���Ƶļ���";
		if ( !stringp(w_id=me->query("jia/id")) ) w_id="my jia";
		else w_id = "my "+me->query("jia/id");
		if ( !stringp(w_or=me->query("jia/or")) ) w_or="ǧ����ľ";
		if ( !(w_lv=me->query("jia/lv")) ) w_lv=1;
	}

	set("material", "fur");
	set_name(w_name, ( {w_id}));
	set("long", "����һ����������Ͼ��Ƶ�����,�����ƺ��̲���ĳ�������������\n");
	set("unit", "��");
	set("value",0);
	set("no_get",1);
	set("no_give",1);
	set("no_drop",1);
	set("no_tie",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_zm",1);    //2015.8 ��� ��������������������Ƕ��̬��ʯ
	set("no_steal",1);
	set("bianren",w_lv);         //  ������������2003��12��17��
	set("ownmake",1);
	set("material", "fur");
//	set("material", "cloth");
//	set_desc(w_lv,w_or,w_name);
	switch(w_or)
	{
	case "ǧ����ľ" :
		set_weight(500);
		set("material", "fur");
		break;
	case "���׽�ĸ" :
		set_weight(1000);
		set("material", "fur");
		break;
	case "��˿����" :
		set_weight(30);
		set("material", "fur");
		break;
	default :
	}
	set("unit", "��");
	if ( objectp(me) && me->query("jia/wear_msg") )
		set("wear_msg", me->query("jia/wear_msg")+"\n");
	else
		set("wear_msg", "$N����"+w_name+"������,��չ���߰�����\n");
	if( objectp(me) && me->query("jia/unequip_msg"))
		set("remove_msg", me->query("jia/unequip_msg")+"\n");
	else
		set("remove_msg", "$N���ϵ�"+w_name+"����������գ�ۼ���Ȼ����Ӱ�١�\n");
	set("armor_prop/armor", w_lv * 10);
	set("armor_type","cloth");
	set("material", "fur");
	setup();
}

int do_hui1(object weapon)
{
	string w_name;
	object me;
	me=this_player();
	w_name=me->query("jia/name");
	if( !weapon )
		return notify_fail("��Ҫ�ݻ�ʲô?\n");
	message_vision(HIR "$N���һ����һ����ף�һ���������¡������¡һ������"
	               +w_name+HIR"��Ϊ����!\n" NOR,me);
	me->set("jia/make",0);
	destruct( this_object() );
	me->delete("weapon");
	me->delete("diablo/cloth");
	me->save();

	return 1;
}

int do_levelup(string arg)
{
	object me, ob;
	object gold;
	int cost = 1;
	int j;
	string id;
	me = this_player();
	id = me->query("id");
	j = (int)me->query("jia/lv");
	if( !arg ) return notify_fail("��Ҫ����ʲ����ף�\n");
	gold = present("gold_money", this_player());
	if( !gold) return notify_fail("������û�н��ӡ�\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if( ob->query("equipped") )
		return notify_fail("�㲻������װ�����˵���ס�\n");
	if( !ob->query("ownmake") )
		return notify_fail("��ֻ�������Լ��������ס�\n");
	if( (int)me->query("qi") < 150 )
		return notify_fail("������������޷�������ף�\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("�����ڵ�����̫�����޷�������ף�\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("�����ڵľ����޷����У����ܶ�����ף�\n");
	if( (int)me->query("score") < 100 * j )
		return notify_fail("�����ڵĽ����������������ܶ�����ף�\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 5000 *j )
		return notify_fail("���Ǳ�ܲ������޷�������ף�\n");

	if(j<6) cost = 15*j;
	else if(j<11) cost = 20*j;
	else if(j<16) cost = 30*j;
	else if(j>500) cost = 500*j;
	else cost = 100*j;
	if((int) gold->query_amount() < cost)
		return notify_fail("������û����" + sprintf("%d",cost)+ "�����ӡ�\n");
	gold->add_amount(-cost);
	me->start_busy(2);
	me->add("bellicosity",cost);
	seteuid(ROOT_UID);
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("score",-100 * j);
	me->add("potential",-5000 * j);
	me->set("jia/lv", j+1);
	me->save();
	reload_object(ob);
	message_vision(HIY "�������һ����һ���������$N��"+ob->name()+HIY"�������ˣ�\n" NOR,me);
	message_vision(HIG "$N��"+ob->name()+HIG"�ĵȼ�����ˣ�\n" NOR, me);
	seteuid(getuid());
	return 1;
}
int do_jianame(string arg)
{
	object me;
	me=this_player();
	if( !arg )
		return notify_fail("���ʲô������?\n");
	if (this_object()->query("bianren") > me->query("jia/lv"))
		return notify_fail("��ֻ�ܸ��Լ����׵�����!\n");
	if( strlen(arg) > 100 )
		return notify_fail("��Ļ����������ֻ��������ʮ���ַ���\n");
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	me->set("jia/name",arg+NOR);
	set("name",arg+NOR);
	write("ok!\n");
	this_object()->create();
	return 1;
}
