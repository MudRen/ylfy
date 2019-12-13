// moyixin.c Īһ��
inherit NPC;
int ask_me();
string ask_me1();
#include <ansi.h>
void create()
{
    set_name("Īһ��", ({ "mo yixin", "mo", "yixin" }));
    set("title", "ҩ���ϰ�");
    set("gender", "����");
    set("long", "������ҽ���߳���Īһ�ġ��������Ը�Ź֣�����ʲô�˶�ҽ�ġ�\n");
    set("age", 65);
    set("int", 30);
    
    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("shen_type", 0);
    set("combat_exp", 500000);
    set("attitude", "heroism");
    set_skill("unarmed", 80);
    set_skill("dodge", 80);
    set_skill("parry", 60);
    set_temp("apply/attack", 70);
    set_temp("apply/defense", 70);
    set_temp("apply/damage", 50);
        set("inquiry", ([
    "�β�":(:ask_me:),
    "��ҩ": (: ask_me1 :),
    "Ǳ�ܵ�": (: ask_me1 :)
        ]) );
    setup();
    add_money("gold", 1);
    carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

string value_string(int value)
{
    if( value < 1 ) value = 1;
    else    if( value < 100 )
        return chinese_number(value) + "��Ǯ";
    else    if( value < 10000 )
        return chinese_number(value/100) + "������"
            + (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
    else
        return chinese_number(value/10000) + "���ƽ�"
            +( (value%10000)/100 ? chinese_number((value%10000)/100) + "������" : "")
            +( (value%10000)%100 ? "��" + chinese_number((value%10000)%100) + "��Ǯ": "");
}
int ask_me()
{
        object ob;
    mapping inv;
    string str,*cond;
    int i;
        ob=this_player(); 
    inv=ob->query_conditions();
       if (((int)this_player()->query("eff_qi") == (int)this_player()->query("max_qi"))
         && ((int)this_player()->query("eff_jing") == (int)this_player()->query("max_jing"))
    && !sizeof(inv)){
                command("say �Ҹ����������,��,�����ڲ���Ҫ�β�!");
        return 1;
    }
        tell_object(ob, "\nĪһ��̧ͷ�����㼸�ۡ�\n");
    str="";
    if (sizeof(inv)){
        cond=keys(inv);
        for (i=0;i<sizeof(inv);i++){
            if (cond[i]=="drunk")
            str+="���������ģ�һ���Ǻ����ˣ�";
            if (cond[i]=="killer"){
                command("say �ٸ���ͨ�����أ��㻹�ǿ��߰ɣ�");
                return 1;
            }
    }
    if (str==""){
        command("say ����ʲô���ɣ��ҿɲ����Σ�");
                return 1;
    }
    ob->set_temp("count",sizeof(inv)*10);
    }
        if ( (int)this_player()->query("eff_qi") < (int)this_player()->query("max_qi") )
        {
             ob->add_temp("count",5); 
             str+="��,���������˵�����! \n";
         }
    if ( (int)this_player()->query("eff_jing") < (int)this_player()->query("max_jing") )
        {
                 ob->add_temp("count",5);
                 str+="��,�㾫Ԫ���˵�����! \n";
        }            
        str+="��"+value_string(1000* ob->query_temp("count"))+"���ȸ�Ǯ�����β��� \n";
        command("say "+str);
                return 1;
}
int accept_object(object who, object ob)
{
    if (who->query_temp("count"))
        if (ob->query("money_id") && ob->value() >= who->query_temp("count")*1000){ 
                who->set("eff_qi",who->query("max_qi"));
                who->set("eff_jing",who->query("max_jing"));
                who->set("eff_gin",who->query("max_gin"));
                who->apply_condition("drunk",0);
                tell_object(who, "Īһ���ó�Щҩ�������£���һ�ᣬ�����ɫ�������ö��ˡ�\n");
            who->set_temp("count",0);
                return 1;
            }  else
                tell_object(who, "Īһ������һЦ����ĳ��ⲻ����������ذɣ�\n");
    return 0;
}
string ask_me1()
{
    return "��...�Ҳ�֪����";
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
