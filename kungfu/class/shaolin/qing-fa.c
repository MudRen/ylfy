// Npc: /kungfu/class/shaolin/qing-fa.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
string ask_for_join();
string ask_for_join();
void create()
{
    set_name("�巨����", ({
        "qingfa biqiu",
        "qingfa",
        "biqiu",
    }));
    set("long",
        "����һλ���ǿ����׳��ɮ�ˣ������û���������ȫ���ƺ��̺�\n"
        "�������������һϮ�ײ��ڱ����ģ��ƺ������ա�\n"
    );
    set("gender", "����");
    set("attitude", "friendly");
    set("class", "bonze");
    set("inquiry",([
        "���"  : (: ask_for_join :),
        "����"  : (: ask_for_join :),
    ]));
    set("age", 30);
    set("str", 25);
    set("int", 17);
    set("con", 50);
    set("dex", 31);
    set("max_qi", 1450);
    set("max_jing", 1200);
    set("neili", 1350);
    set("max_neili", 350);
    set("jiali", 30);
    set("combat_exp", 5000);
    set("score", 100);
    set_skill("force", 50);
    set_skill("hunyuan-yiqi", 50);
    set_skill("dodge", 50);
    set_skill("shaolin-shenfa", 50);
    set_skill("unarmed", 50);
    set_skill("jingang-quan", 50);
    set_skill("parry", 50);
    set_skill("buddhism", 50);
    set_skill("literate", 50);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "jingang-quan");
    map_skill("parry", "jingang-quan");
    
    create_family("������", 40, "����");
    setup();
        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}
void init()
{
    add_action("do_kneel", "kneel");
   call_out("check_user",1,this_player());
}

void check_user(object me)
{
    object link_ob;
    if (!me || environment(me)!=environment(this_object())) return;
    if ( (me->query("family/family_name") == "������"))
    {
        if (me->query("class") != "bonze")
        if (time() - me->query("family/enter_time")>8640){
            message_vision(BOLD "$N����$n�����˰��죬��$nҡ��ҡͷ���㳾Դδ�ˣ�������ɽȥ�ɣ�\n" NOR,this_object(),me);
         me->delete("family");
         me->set("title","��ͨ����");
         if (link_ob=me->query_temp("link_ob"))
             me->set("name",link_ob->query("name"));
         }
    }
    add_action("do_kneel", "kneel");
}
string ask_for_join()
{
    object me;
    me = this_player();
    if ( time()-(int)me->query("kill_bonze")<86400)
        return "�ߣ���������ֵ���ͽ��������������\n";
    if( (string)me->query("class")=="bonze" )
        return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��\n";
    if( (string)me->query("marry"))
        return "�����ӷ�ʩ����Եδ��,�����ҿ��ţ�\n";
    if( (string)me->query("gender") != "����" )
        return "�����ӷ����գ����գ�Ůʩ������������ҷ𣬿�ȥ��ɽ�����ܽ䡣\n";
    me->set_temp("pending/join_bonze", 1);
    return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}
int do_kneel()
{
    object me = this_player();
    string *prename =
//   ({ "��", "��", "��", "��" });
     ({ "��", "��", "��", "Բ", "��", "��", "��","ɫ" });
    string name, new_name;
    if( !me->query_temp("pending/join_bonze") )
        return 0;
    message_vision(
        "$N˫�ֺ�ʮ�����������ع���������\n\n"
        "$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n",
        me, this_object() );
    name = me->query("name");
    new_name = prename[random(sizeof(prename))] + name[0..1];
    command("say �ӽ��Ժ���ķ�������" + new_name + "��");
    command("smile");
    me->delete_temp("pending/join_bonze");
    me->set("name", new_name);
    me->set("class", "bonze");
    me->set("K_record", me->query("PKS") + me->query("MKS"));
    me->set("shen_record", me->query("shen"));
        me->set("shen", 0);
    return 1;
}
void attempt_apprentice(object ob)
{
    if( (string)ob->query("gender") != "����" )
    {
        command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
        return;
    }
    if ( time()-(int)ob->query("kill_bonze")<86400)
    {
      command("say �ߣ���������ֵ���ͽ��������������");
      return;
    }
    
    if( (string)ob->query("class")!="bonze" )
    {
        command ("say �����ӷ�ƶɮ�������������׼ҵ��ӡ��ˡ�");
    }
    command("say �����ӷ����գ����գ�");
    command("recruit " + ob->query("id"));
}
