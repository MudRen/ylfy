// npc: shijian.c
// Jay 3/26/96
#include <ansi.h>
inherit NPC;
void create()
{
    set_name("�̹�", ({ "shigun"}) );
    set("nickname", HIB "��" NOR );
    set("gender", "����" );
    set("age", 20);
    set("long",     
        "��ͷ�ϰ��Űײ�ͷ����һϮ���ۣ�û��һ˿���塣\n");
    set("str", 25);
    set("dex", 20);
    set("con", 17);
    set("int", 30);
    set("shen_type", 0);
    set("max_neli",500);
    set("jiali",50);
    set_skill("unarmed", 100);
    set_skill("dodge", 100);
    set_skill("force",150);
    set_skill("sword",150);
    set_skill("parry",90);
    set_temp("apply/attack", 50);
    set_temp("apply/defense", 50);
    set_temp("apply/damage",50);
    set("combat_exp", 250000);
    set("score",0);
    
    set("attitude", "peaceful");
        
    set("inquiry", ([
        "����"  : "ʦ�����Ұ���������������������Ҳ����һ����Ӱ��˭Ҫ�����أ�\n",
        "ԭ��"  : "�������ú�˿���񣬺��׽�ĸ��ǧ����ľ����Ч������һ����\n",
    ]) );
    setup();
    carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
    ::init();
    add_action("do_zhu","zhu");
}
int accept_object(object who, object ob)
{   
    if(!(who->query_temp("club") ) ){
        message_vision(HIC"ʦ��û��ͬ��Ϊ������������ذɣ�\n"NOR, who);
        return 0;
    }
    who->delete_temp("club");
    who->set_temp("m_club",1);
    switch ((string)ob->query("name") ) 
    {
        case "ǧ����ľ": 
            who->add_temp("shenmu",1);
            break;
        case "���׽�ĸ":
            who->add_temp("jinmu",1);
            break;
        case "��˿����": 
            who->add_temp("hanzhu",1);
            break;
        default :
            message("vision","����ʲô��ʦ��˵�ⲻ���������������",who);
            return 0;
    }
    message("vision","�̹���ͷ������һ�����е�"+(string)ob->query("name")+
            "���˵�ͷ˵��\n", who);
    message("vision","���������������ھͿ�ʼ����\n", who);
    write("����λ"+RANK_D->query_respect(who)+"���������ְɣ�(zhu ������������(ʹ����ɫ��ο�help nick))\n");
    return 1;
}
int do_zhu(string arg)
{
    string o_name,id,w_name;
    object club,make_time;   //���ɵ��������
    object me;
    me = this_player();
    if(!(me->query_temp("m_club")) ) 
        return notify_fail("ʲô?\n");
    if((me->query("weapon/make")) ){
        say("�̹�һ��ãȻ�����Ѿ���һ������������ˣ�������ʲô���ѵ�������ô��\n");
        return 2;
    }
    if( !arg )
        return notify_fail("�̹������˵����ù������ƺ��ٶ���˵��\n");
    sscanf(arg ,"%s" ,w_name);
    id="my club";
    if(!w_name||!id)
        return notify_fail("ʲô?(ʹ��zhu ������������\n)");
    me->delete_temp("m_club");
    me->delete_temp("get_orc");
    me->delete_temp("or");
    if(me->query_temp("shenmu") ) o_name="ǧ����ľ";
    if(me->query_temp("jinmu") )   o_name="���׽�ĸ";
    if(me->query_temp("hanzhu") )   o_name="��˿����";
    make_time=NATURE_D->game_time();
    message_vision(me->name()+"������һ�ᣬ���̹�����˵�˼��仰���̹����˵�ͷ��˵���ðɣ�\n",me );
    message_vision("\n�̹��ع�����ת�������һ���޴�Ļ�¯���Ķ�����ȼ�������ܵĴ��˵����ʼ��\n",me );
    message_vision(BLU "$N˫����סһ���޴���������͵���¯�н�������������"+o_name+"��ȥ��\n" NOR,me);
    message_vision(RED "ֻ�������һ�����죬��ͷ��"+o_name+"ճ����һ��\n" NOR,me );
    message_vision(YEL "$Nֻ��������һ�ȣ�������ѪҺ�ƺ���������������\n" NOR,me);
    message_vision(HIM "һ����Ѫ�����������������ԴԴ���ϵ���¯�е�"+o_name+"ӿȥ��\n" NOR,me );
    if( (me->query("qi"))<(me->query("max_qi")) || (me->query("jing"))<(me->query("max_jing")) || (me->query("neili"))<(me->query("max_neili")) )
    {
        message_vision(HIR "ͻȻ$N������Ѫһ��ӿ��һ�������Ӳ������������� \n" NOR, me);
        me->set("neili",0);
        me->unconcious();
        return 1;
    }
    message_vision(HIR "ֻ������һ�����죬һ���޹���¯��ٿȻԾ�𡣻���һ������͵���$N��ǰ�ش�������\n" NOR,me );
    say("�̹���״��У�������ɣ���Ѫ�Լ�����������\n");
    message_vision("$Nֻ������ǰһ����һ����ӰѸ���ޱȵĵ�����$N����ǰ��\n",me );   
    message_vision("�޹�͸�ش������̹��Һ�һ������Ѫ�������������ǣ�\n",me );
    message_vision(RED "�̹�����һ�����ȣ������˵��ϡ��̹��Ѿ�����һϢ�ˡ�\n" NOR,me);
    this_object()->set("max_qi",10);
    message_vision("�޹��ַ����������ɵ���գ�����һ����ص����ϡ�\n¯�еĻ����ˡ�һ�ҵľ����������Σ�һ���ֹ��ڳ��š�\n",me );
    me->set("qi",10);
    me->set("jing",10);
    me->set("neili",0);
    w_name = replace_string(w_name, "$BLK$", BLK);
    w_name = replace_string(w_name, "$RED$", RED);
    w_name = replace_string(w_name, "$GRN$", GRN);
    w_name = replace_string(w_name, "$YEL$", YEL);
    w_name = replace_string(w_name, "$BLU$", BLU);
    w_name = replace_string(w_name, "$MAG$", MAG);
    w_name = replace_string(w_name, "$CYN$", CYN);
    w_name = replace_string(w_name, "$WHT$", WHT);
    w_name = replace_string(w_name, "$HIR$", HIR);
    w_name = replace_string(w_name, "$HIG$", HIG);
    w_name = replace_string(w_name, "$HIY$", HIY);
    w_name = replace_string(w_name, "$HIB$", HIB);
    w_name = replace_string(w_name, "$HIM$", HIM);
    w_name = replace_string(w_name, "$HIC$", HIC);
    w_name = replace_string(w_name, "$HIW$", HIW);
    w_name = replace_string(w_name, "$NOR$", NOR);
    me->set("weapon/name",w_name+NOR);  //����������
    me->set("weapon/make",1);       //����������ֹ����ı�־      
    me->set("weapon/id",id);        //�����Ĵ���
    me->set("weapon/lv",1);     //�����ȼ�
    me->set("weapon/or",o_name);    //��¼����ԭ��
    me->set("weapon/value",0);          //��¼�����������еĵ���    
    me->set("weapon/type","��");
    me->set("weapon/time",make_time);
    club=new("/d/npc/m_weapon/weapon/m_club",1);    //�����¹�
    club->move(this_player());
    message_vision("�̹�������ϣ����Ű߰�Ѫ������Щ���ֵľ޹���˵��\n�������ѡ����ɡ������̹������񡣡���Ҳ������ˡ�������\n",me );
    say("�̹����ѵ�˵���������������պã��Ҹ����ˡ�����\n");
    message_vision("�̹�˵�ꡣٿ�ı㲻���ˡ�\n",me);
    this_object()->die();
    return 1;
}