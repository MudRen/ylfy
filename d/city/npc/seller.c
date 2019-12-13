inherit NPC;
void create()
{
    set_name("����", ({ "wang ba", "wang", "ba" }));
    set("long", "һ����������ļһһ�������ص����飬��֪�����Ǹ����ˡ�\n");
    set("nickname", "�˷���");
    set("rank_info/respect", "����");
    set("gender", "����");
    set("age", 35);
    set("shen_type",-1);
    set("combat_exp", 5000);
    set("per",10);
    set_skill("unarmed", 100);
    set_skill("blade", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    
    set_temp("apply/attack", 15);
    set_temp("apply/defense", 15);
    set_temp("apply/damage", 20);
    setup();
    carry_object("/clone/cloth/blk_cloth")->wear();
}
    
void init()
{
    add_action("do_sell","sell");
    add_action("do_redeem","redeem");
}
int do_sell(string arg)
{
    object obj;
    if (!arg)    return notify_fail("��Ҫ��ʲô��\n");
    if( !(obj = present(arg, this_player())) )
        return notify_fail("������û���ⶫ����\n");
    if (!obj->is_character() || obj->is_corpse() )
        return notify_fail(this_object()->name()+"ҡ��ҡͷ���Ҷ��ⶫ��û��Ȥ��\n");
    if (obj->query("combat_exp") <1000 )
        return notify_fail(obj->name()+"��ֵǮ��\n");
}
int do_redeem(string arg)
{
    object room;
    if (!arg)   return notify_fail("������˭��\n");
    if (! room=find_object("/d/city/cangku") )
        room=load_object("/d/city/cangku");
    if (!room->do_check(arg))
        return notify_fail("˭��û��˵����\n");
    
}