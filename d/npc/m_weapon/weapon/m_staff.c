// m_sword.c
#include <ansi.h>
#include <weapon.h>
//inherit M_WEAPON;
inherit S_WEAPON;	
int do_rename(string arg);
void init()
{
    //add_action("do_duanlian","duanlian");
    add_action("do_hui","hui");
	add_action("do_levelup1","jiwu");
    add_action("do_rename","rename");
}
void create()
{   
    object me;
    string w_name,w_id,w_or;
    int w_lv;
    me = this_player();
//��������
    w_name=me->query("weapon/name");
    w_id = me->query("weapon/id");
    w_or = me->query("weapon/or");
    w_lv = me->query("weapon/lv");
    set_name(w_name, ({w_id,"staff"}));
    set("unit", "��");   
  //set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
	set("no_tie",1);
	set("no_zm",1);    //2015.8 ��� ��������������������Ƕ��̬��ʯ���Ż�������
    set("bianren",w_lv);         //  ������������2003��12��17��	
    set("weapon/id_name", me->query("id")); //����idʶ�𣬷�ֹ���˵��� 2015.10	
    set_desc(w_lv,w_or,w_name);
    switch(w_or)
        {
        case "ǧ����ľ" :
            set_weight(6000+w_lv*500);
            set("material", "iron");
            break;
        case "���׽�ĸ" :
            set_weight(8000+w_lv*500);
            set("material", "steel");
            break;
        case "��˿����" :
            set_weight(4000+w_lv*500);
            set("material", "bamboo");
            break;
        default :
        } 
    set("wield_msg", "$N������һ�����ͳ���һ��"+w_name+"\n");
    set("unwield_msg", "$N����"+w_name+"һ�ӣ�գ�ۼ���Ȼ����Ӱ�١�\n");
    init_staff(w_lv * 10,1);
    setup();
}   
/*int do_duanlian(string arg)
{
    object me,weapon;
    int w_zhi, w_level;
    string w_or;
    me=this_player();
    if( !arg || !id(arg) )
        return notify_fail("��Ҫ����ʲô?\n");
    if( (int)me->query("max_neili") < 1000 )
        return notify_fail("��������������޷��������壡\n");
    if( (int)me->query("qi") < 150 )
        return notify_fail("������������޷��������壡\n");
	if( !(me->query("weapon/make")) )
        return notify_fail("�����������?\n"); //����ж����޷�duanlian ���˵�����
    if( (int)me->query("eff_qi") < 50 )
        return notify_fail("�����ڵ�����̫�����޷��������壡\n");
    if( (int)me->query("eff_jing") < 50 )
        return notify_fail("�����ڵľ����޷����У����ܶ������壡\n");
    if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
        return notify_fail("���Ǳ�ܲ������޷��������壡\n");
    message_vision(HIR "$N�����ȶˣ�һ������˿˿�Ĵ��˽�ȥ��\n" NOR, me);
    me->add("max_neili",-10);
    //me->set("neili", (int)me->query("max_neili"));
    me->add("qi",-150);
    me->add("eff_qi",-30);
    me->add("eff_jing",-30);
me->add("potential",-2);
    w_zhi = (int)me->query("weapon/value");
    w_zhi++;
    me->set("weapon/value", w_zhi);
    w_or = (string)me->query("weapon/or");
    w_level = (int)me->query("weapon/lv");
    if( w_zhi >= ((w_level + 1) * (w_level + 1)))
    {
        w_level++;
        me->set("weapon/lv", w_level);
        message_vision(HIY "�������һ����һ���������$N�����壬�����ˣ�\n" NOR,me);
        message_vision(HIG "$N���ȵĵȼ�����ˣ�\n" NOR, me);
        weapon=this_object();
        if(weapon->query("equipped") ) 
            weapon->unequip();
        reload_object( weapon );
        me->set("weapon/value",0);
        return 1;
    }
    message_vision(RED "$N���ȵ�Ӳ�������!\n" NOR, me);
    return 1;
}*/
int do_levelup1(string arg)
{
	object me, ob;
	object gold;
	int cost = 1;
	int j;
	string id;
	me = this_player();
	id = me->query("id");
	j = (int)me->query("weapon/lv");
	if( !arg ) 
		return notify_fail("��Ҫ����ʲ��������\n");
	gold = present("gold_money", this_player());
	if( !gold) 
		return notify_fail("������û�н��ӡ�\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");
	if( !(me->query("weapon/make")) )
        return notify_fail("�����������?\n"); //����ж����޷�duanlian ���˵�����
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if( ob->query("equipped") )
		return notify_fail("�㲻������װ�����˵�������\n");
	if( (int)me->query("qi") < 150 )
		return notify_fail("������������޷�����������\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("�����ڵ�����̫�����޷�����������\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("�����ڵľ����޷����У����ܶ���������\n");
	if( (int)me->query("score") < 100 * j )
		return notify_fail("�����ڵĽ����������������ܶ���������\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 5000 *j )
		return notify_fail("���Ǳ�ܲ������޷�����������\n");

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
	me->set("weapon/lv", j+1);
	me->save();
	reload_object(ob);
	message_vision(HIY "�������һ����һ���������$N��"+ob->name()+HIY"�������ˣ�\n" NOR,me);
	message_vision(HIG "$N��"+ob->name()+HIG"�ĵȼ�����ˣ�\n" NOR, me);
	seteuid(getuid());
	return 1;
}
int do_hui(string weapon)
{   
    string w_name;
    object me;
    me=this_player();
    w_name=me->query("weapon/id");
    if( !weapon || w_name!=weapon)
        return notify_fail("��Ҫ�ݻ�ʲô?\n");
    message_vision(HIR "����һ����һ�����ȣ�һ���������¡������¡һ������"
            +this_object()->name()+HIR+"��Ϊ����!\n" NOR,me);
    me->delete("weapon");
	me->delete("diablo/staff");
    
    me->save();
    destruct( this_object() );
    return 1;
}
int do_rename(string arg)
{
    object me;
    me=this_player();
    if( !arg )
        return notify_fail("���ʲô������?\n");
if (this_object()->query("bianren") > me->query("weapon/lv"))    	
return notify_fail("��ֻ�ܸ��Լ���������!\n");		
if( strlen(arg) > 100 )          		
return notify_fail("��ı����������ֻ��������ʮ���ַ���\n");     	
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
    me->set("weapon/name",arg+NOR);
    set("name",arg+NOR);
    write("ok!\n");
    this_object()->create();
    return 1;
}
