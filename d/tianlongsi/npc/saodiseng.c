inherit NPC;
string ask_me1();
string ask_me2();
void create()
{
    set_name("ɨ��ɮ", ({ "saodi seng","seng"}) );
    set("gender", "����" );
    set("class", "bonze");
    set("age", 100);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 3000);
    set("max_neili", 3000);
    set("jiali", 20);
    set("combat_exp", 80000);
    set_skill("dodge", 100);
    set_skill("parry", 100);
    set_skill("staff", 100);
    set_skill("buddhism", 120);
    set_skill("literate", 120);
    set("inquiry" ,([
    "������" : (:ask_me1():),
    "��ʧ" : (:ask_me2():),
    ]));
    setup();
    carry_object("d/tianlongsi/obj/b-jiasha")->wear();
}
string ask_me1()
{
    object me=this_player();
    if(me->query_temp("marks/ask_temp1"))
        return "�����Ǳ��µ�����֮�������겻֪Ϊ�ζ�ʧ�ˡ���\n";
    else
        return "�����˵�˵�ʲô����\n";
}
string ask_me2()
{
    object me=this_player();
    if(me->query_temp("marks/ask_temp1"))
        {
        me->set_temp("marks/ask_temp2",1);
        return "������������ֻ����һ����Ӱ�����Ϸ��£����������ˡ�\n";
        }
    else
        return "�����˵�˵�ʲô����\n";
}
