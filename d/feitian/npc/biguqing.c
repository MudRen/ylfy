//Npc �ȹ���ʮ��
//diabio(����)2003.3.1
#include <ansi.h>
inherit NPC;
int ask_tianxiang();
inherit F_MASTER;
void create()
{
        set_name("�ȹ���ʮ��", ({ "biguqing shilang", "shilang" }));
        set("long", "������糴彣�ĵ�ʦ���� \n");
        set("title", HIR"����������"HIY"����������"NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude","peaceful");
        set("str", 500);
        set("dex", 500);
        set("con", 500);
        set("int", 500);
        set("per", 500);  
        set("tianyu_1",1);
        set("jing", 2500000);
        set("max_jing", 2500000);  
        set("qi", 5200000);
        set("jiali", 200000);
        set("max_qi", 5200000);
        set("jingli", 320000);
		set("max_jingli", 320000);
        set("neili", 14000000);
        set("max_neili", 4000000);
        set("combat_exp", 2100000000);
        set("xyzx_sys/level", 3800); 
		
        set_skill("dodge",4000);      
        set_skill("unarmed",4000);
        set_skill("parry",4000);
        set_skill("blade",4800);
        set_skill("feitian-yujianliu",2800);
        set_skill("wuxing-dun",2800);
        set_skill("shayi",2800);
        set_skill("aikido",2800);
        set_skill("shayi-xinfa",2800);
        set_skill("shiren-jianfa",2800);
        set_skill("shiren-quanfa",2800);
        set_skill("force",3000);
        set_skill("huoxinliu-jianfa",2800);
        set_skill("literate",2500);

        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
        map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        create_family("����������", 5, "����");
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
                set("inquiry", ([
           "����������":     "��ս��ʱ����ʼ����������������书��",
           "��������": (:ask_tianxiang:),
           "糴彣��":   "�������ǲ�Тͽ����"]) );
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/wushidao")->wield();
}

void attempt_apprentice(object ob)
{
        if(ob->query("family/family_name")!="����������")
        {
                command("say �����ɵ��Ӳ���ѧ�ҹ���\n");
          return 0;
        }
        if(ob->query("combat_exp")<1000000)
        {
                 command("say ���ʵս�����������Ҳ��ܴ����㹦��\n");
            return 0;
        }
       	if ((int)ob->query_skill("huoxinliu-jianfa", 1) < 200) {
		command("say ��Ļ���������̫���ˣ���δ��������Ķ������ѧϰ�ҵ��书�ء�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰѻ���������������������ɣ�");
		return;
        }
	if ((int)ob->query_skill("shayi-xinfa", 1) < 200) {
		command("say ���ɱ���ķ�̫��,���¿��Ʋ���ɱ�⡣"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰ�ɱ���ķ�������������ɣ�");
		return;
	}
	if ((int)ob->query_skill("aikido", 1) < 200) {
		command("say ��Ŀ��ֵ�̫�͡�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰѿ��ֵ�������������ɣ�");
		return;
	}
	if ((int)ob->query_skill("wuxing-dun", 1) < 200) {
		command("say ������ж�̫�͡�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰ����ж�������������ɣ�");
		return;
	}
    if ((int)ob->query_skill("shayi", 1) < 200)
    {
        command("say ����֮������ɱ�⡣");
        command("say " + RANK_D->query_respect(ob) +
            "���ɱ��̫���ˣ�");
        return;
    }
	command("recruit " + ob->query("id"));
	ob->set("title",HIR"��������������"HIR"����"NOR);
       ob->set("class", "yujianliu");
}
int ask_tianxiang()
{
    object ob;
    ob = this_player();

    tell_object(ob,"�ȹ���ʮ��˵�����콵��������߽�������Ҫѧ�������������ƴ���У�����������˾͸�������Ҥ��\n"); 
      command("go south");
      command("go west");
   command("sigh");
   return 1;
}
void kill_ob(object me)
{
if(!this_player())
{
::kill_ob(me);
return;
}
 if(this_player()->query("family/family_name")=="����������")
{
	command("say ���ҪС���ˣ��ó������������ɱ�ҡ�\n");
       this_player()->set("feitian/bigu",1);
	::kill_ob(me);
}
}
               
void die()
{
        object ob, me;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (me && me->query("family/family_name")=="����������")
{ 
        message_vision("\n$N�������㲻���ѹ��������������������˶�����ˣ���Ҫѧ����߽������ž��������������㲻��̫�ѹ���\n", this_object());
me->set("feitian/tianxiang",1);
message_vision("\n������һ��������ᵽ�����������ľ��衣\n", this_object());
}
::die();
}