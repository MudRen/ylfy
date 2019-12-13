inherit NPC;
int ask_me();
int accept_fight(object ob);
int checking(object me, object ob);
void create()
{
    set_name("����", ({ "ku rong","ku"}) );
    set("gender", "����" );
    set("class", "bonze");
    set("age", 100);
    set("str", 40);
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("qi", 3000);
    set("max_qi", 3000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 5000);
    set("max_neili", 5000);
    set("jiali", 50);
    set("combat_exp", 2000000);
    set_skill("force", 250);
    set_skill("kumu-shengong", 150);
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("unarmed", 205);
    set_skill("yiyang-zhi", 200);
    set_skill("buddhism", 200);
    set_skill("literate", 180);
    map_skill("force", "kumu-shengong");
    map_skill("unarmed", "yiyang-zhi");
    
    set("inquiry" ,([
    "������" : (: ask_me :),
    "��������" : (: ask_me :),
    "�����񽣽���" : (: ask_me :),
    ]));
    setup();
    carry_object("d/tianlongsi/obj/p-jiasha")->wear();
    carry_object("d/tianlongsi/obj/sengmao")->wear();
}
int ask_me()
{
        if ((int)this_player()->query_temp("marks/find_temp")&&this_player()->query_temp("marks/ask_temp3")) 
        {
            say(
"���ٿ���" + this_player()->name() + "һ�ۣ�˵����\n"
"��λʩ����Ȼ������ʩ������ʤ�����ľͿɵõ��������ס�\n");
 this_player()->set_temp("marks/ask_temp4", 1);
        }
    else  message_vision("$N����$nһ�ۣ�˵�������Ŀɲ�֪��ʲô���������ס�\n",this_object(),this_player());
    return 1;
}
int accept_fight(object ob)
{
        object me;
        me = this_object();
      
        if ((int)this_player()->query_temp("marks/find_temp")&&this_player()->query_temp("marks/ask_temp3")&&ob->query_temp("marks/ask_temp4")) {
           message_vision("$N��$p˵���ðɣ���" 
             "�Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��\n",me,ob);
             command("exert powerup");
          remove_call_out("checking");
          call_out("checking", 1, me, ob);
          return 1;
        }
        else
            return 0;
}
int checking(object me, object ob)
{
        object obj;
        int my_max_qi, his_max_qi;
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");
        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }
        if ( !present(ob, environment()) ) return 1; 
        if (!living(me))
            me->revive();
        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                say(
                  "����˵��ʩ�����ֹ�Ȼ���������������\n"
                  "�Ȿ������������ȥ�ɡ�\n"
                );
                obj= new("/d/tianlongsi/obj/liumai-jianpu"); 
                obj->move(ob);
                message_vision("$N����$nһ���顣\n", me, ob);
        ob->delete_temp("marks");
                return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
                   "����˫�ֺ�ʮ������Եһ��������ʩ����ذɡ�\n"
                );
                message_vision("$N�Կ��ٴ�ʦ���������ؿ���һ��ͷ���뿪Ĳ���á�\n", ob);
                ob->move("/d/tianlongsi/banruotai");
                return 1;
        }
        return 1;
}
