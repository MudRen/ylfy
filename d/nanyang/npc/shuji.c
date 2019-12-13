// shuji.c �������
inherit NPC;
void create()
{
    set_name("�����", ({ "liu shuji", "liu", "shuji" }));
    set("title", "������Ʒ�Ĺ�");
    set("nickname", "ȫ��һ֧��");
    set("shen_type", 1);
    set("str", 50);
    set("gender", "����");
    set("age", 35);
    set("long",
        "���������ǻ�������С��һ����Ա���ƹ���ҵĻ��ڡ�\n");
    set("combat_exp", 1500);
    set("attitude", "friendly");
    set("inquiry", ([
        "����" : "Ҫ�����ȵý�Ǯ��",
    ]));
    
    setup();
    carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
    object ob;
    
    ::init();
    if (interactive(ob = this_player()) && !is_fighting()) {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
    add_action("do_name","��");
    add_action("do_name","change");
}
void greeting(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    switch(random(2)) {
    case 0 :
        say("�����Ц���е�˵������λ" + RANK_D->query_respect(ob) +
            "���������Ъ�����ɡ�\n");
        break;
    case 1 :
        say("�����˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
            "�����˰�����Ҫ������\n");
        break;
    }
}
int accept_object(object who, object ob)
{
    
    if (ob->query("money_id") && ob->value() >= 1000000)
    {
        tell_object(who, "�����Ц���е�˵�����ðɣ������ǿ�������ȡ��ʲô���������֡�\n");
        tell_object(who, "����룺�� �µ���������\n");
        who->set_temp("fee_paid",1);
        return 1;
    }
    else if (ob->query("money_id") && ob->value() < 1000000) 
    {
        tell_object(who, "����Ǻٺ�һЦ��˵�������������Ǯ�� �����ҿ�û�����㰡��\n");
        return 1;
    }
    return 0;
}
int do_name(string target)
{
    object me;
    string old_name;
    me = this_player();
    old_name = me->query("name");
    if( !me->query_temp("fee_paid") ) 
        return notify_fail("����������˵�������ܽ�����ʲ�ᣬ���ɵ��ȸ�Ǯ�ģ�\n");
    if( !target) 
        return notify_fail("������Ի󲻽��˵��������������µ�����ѽ��\n");
    if( old_name == target )
        return notify_fail("�������ֵض���˵��������Ǯ�ǲ�������̫�����ˣ�\n");
    if (!LOGIN_D->check_legal_name(target))
        return notify_fail("������ֲ��Ϸ���������һ�����ְɣ�\n");
    if( me->query_temp("name_chgd") ) 
        return notify_fail("����ǲ�����˼��Ц��Ц��������ȥ���Ҷ��ǲ�������˭�ˡ�\n");
    me->delete_temp("fee_paid");
    me->set_temp("name_chgd",1);
    me->set("name", target);
    command("chat " + old_name + "(" + me->query("id") +")�����ڿ�ʼ����Ϊ��" + me->query("name") + "������Ժ���ϴ����ˣ�\n");
    return 1;
}

