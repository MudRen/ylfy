#define WEAPON_NEED_GOLD 1  //��������Ҫ�Ļƽ���
#define MAX_WEAPON_SELF  3  //���������������
#include <ansi.h>
inherit NPC;
int do_ding(string arg);
string colorstr(string arg);
int query_gold_of_user(object user);
int qu_didao();
void create()
{
    set_name("����ר��", ({ "superman" }) );
        set("gender", "����" );
    set("age", 52);
        set("long",
        "��λ����������ר����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
    set("rank_info/respect", "����ר����");
     set("inquiry", ([
                "ؤ��" : "����ؤ���������紦��\n",
                "�ص�" : (: qu_didao :),
               ]) );
    setup();
}
int qu_didao()
{
say ("����ר��˵��:�����ð��ؤ����Ӿ͵���ù��\n");
 this_player()->move("/d/choyin/didao8");
 return 1;
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
    add_action("do_ding", "ding");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
            say( "����ר��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "��ʲô�һ���ְ�?\n");
                        break;
                case 1:
            say( "����ר���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
            say( "����ר��˵������λ" + RANK_D->query_respect(ob)
                + "����һ���Լ���������!\n");
                        break;
        }
}
int do_ding(string arg)
{
    object ding_weapon, me = this_player();
    string type, cname, ename, name;
    string *weapon_list, *files_list;
    mapping weaponself, this_weapon;
    int weaponself_counter, i;
    weapon_list=({
    "whip",
    "axe",
    "hammer",
    "sword",
    "blade",
    "staff",
    "dagger",
    "spear",
    });
    files_list=({
    "/obj/weapon/whip",
    "/obj/weapon/axe",
    "/obj/weapon/hammer",
    "/obj/weapon/sword",
    "/obj/weapon/blade",
    "/obj/weapon/staff",
    "/obj/weapon/spear",
    });
    
    this_weapon=([]);
    weaponself=me->query("weaponself");
    weaponself_counter=sizeof(weaponself);
    if( !arg || sscanf(arg, "%s %s %s", type, cname, ename)!=3 )
        return notify_fail("ָ���ʽ��ding <��������> <��������> <Ӣ�Ĵ���>\n");
    if ( weaponself_counter>=MAX_WEAPON_SELF ){
        printf("�����ֻ�ܶ���%i������\n", MAX_WEAPON_SELF);
        return notify_fail("�������������� :(((\n");
    }
    if ( weaponself_counter==0 ) weaponself=([]);
    if( strlen(cname) > 50 || strlen(ename)>50 )   return notify_fail("����̫���ˣ���һ����һ��ġ�\n");
    name = colorstr( cname );
    this_weapon["name"] =name;
    this_weapon["ename"]=ename;
    this_weapon["power"]=0;
    i=member_array( type, weapon_list);
    if( i!=-1 ) {
        if ( !query_gold_of_user( me ) ) return 1; //no enough gold,so return
        this_weapon["type"]=weapon_list[i];
        ding_weapon = new( files_list[i] );
        ding_weapon->set_name( name, ({ename+" "+weapon_list[i], ename }) );
        ding_weapon->set( "makeself",1 );
        ding_weapon->set("no_sale", 1);
        ding_weapon->set("no_get", 1);
        ding_weapon->set("no_drop", 1);
        ding_weapon->move(me);
        weaponself[weaponself_counter]=this_weapon;
        me->set("weaponself",weaponself );
        me->save();
    }else{
        printf("��ֻ�ܶ��� ");
        for(i=0;i<sizeof(weapon_list);i++)printf("%s,",weapon_list[i]);
        printf("֮һ\n");
        return notify_fail("û����˵������\n");
    }
    write("\nOK!\n");
    return 1;
}
string colorstr(string arg)
{
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
    return (arg+NOR);
}
int query_gold_of_user(object user)
{
        object gold;
        int gold_number;
        gold_number=0;
        gold=present("gold_money",user);
        if (gold) {
                gold_number=gold->query_amount();
                if ( gold_number>=WEAPON_NEED_GOLD )
                        gold->set_amount(gold_number-WEAPON_NEED_GOLD);
                return 1;
        }else{
            printf("����һ��������Ҫ%i������\n",WEAPON_NEED_GOLD);
            return 0;
        }
}
