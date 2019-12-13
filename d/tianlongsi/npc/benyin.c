inherit NPC;
inherit F_MASTER;

string ask_me();
void create()
{
    set_name("����", ({ "ben yin","yin"}) );
    set("gender", "����" );
    set("title", "����������");
    set("class", "bonze");
    set("age", 70);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("qi", 3500);
    set("max_qi", 3500);
    set("jing", 1500);
    set("max_jing", 1500);
    set("neili", 3000);
    set("max_neili", 3000);
    set("jiali", 150);
    set("combat_exp", 800000);
    set_skill("force", 120);
    set_skill("yiyang-zhi", 120);
    set_skill("dodge", 180);
    set_skill("parry", 120);
    set_skill("unarmed", 185);
    set_skill("kumu-shengong", 180);
    set_skill("buddhism", 120);
    set_skill("literate", 120);
    map_skill("force", "kumu-shengong");
    map_skill("unarmed", "yiyang-zhi");
    set("inquiry" ,([
    "������" : (:ask_me():),
    "��������" : "��ʩ�������Ǵ�ʲô����ɣ���\n",
    "������" :  "��ʩ������������ҽ��������ɣ���\n",
    ]));
    
    create_family("����μ�",19,"����");
    
    setup();
    carry_object("d/tianlongsi/obj/y-jiasha")->wear();
}

string ask_me()
{
    object me=this_player();
    if(me->query_temp("marks/ask_temp0"))
        {
        me->set_temp("marks/ask_temp1",1);
        return "�����Ǳ��µ�����֮����������ǰ������ʧ��ʩ�������һش��\n ���ı�����л����\n";
        }
    else
        return "��ʩ���������ԡ���\n";
}

int accept_object(object who, object ob)
{
if (  (string)ob->short() == "����(Jin he)")        {   	
        message_vision("�����ϲ��������лʩ����ʩ��������Ե�ˣ��뵽Ĳ����ȡ����֮����\n", who);
        who->set_temp("marks/find_temp",1);
        who->move("/d/tianlongsi/munitang");
        return 1;
        }
    return 0;
}

void attempt_apprentice(object ob)
{
        if (!(int)ob->query_temp("tmark/��") ) {
                command("say ���º������޽�����ʩ����ذ�!");
          return;
        } else {
                command("say ��Ȼ���ϻ�ү�Ը������ģ�Сɮ����Ϊ���Ѱ�!");
                command("nod");
                command("recruit " + ob->query("id") );
        }
}
