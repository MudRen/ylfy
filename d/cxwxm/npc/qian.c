// qian.c �Ϲ���ٻ
// marry 99.8

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�Ϲ���ٻ", ({ "shangguan yunqian", "qian","shangguan","yunqian" }));
        set("nickname", HIM "�һ�Ů" NOR);
        create_family("����������", 3,"����");
        set("jihao",1);
        set("long","�����ǳ�����������������Ů���һ�Ů���Ϲ���ٻ��");
        set("gender", "Ů��");
        set("age", 17);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);
        set("dex", 30);
        
        set("max_qi", 40000);
        set("max_jing", 9000);
        set("neili", 100000 + random(50000));
        set("max_neili", 100000);
        set("jiali", 300);
        set("combat_exp", 60000000);
        set("score", 500000);

        set_skill("force", 380);
        set_skill("dodge", 370);
        set_skill("unarmed",320);
        set_skill("parry", 390);
        set_skill("whip", 390);
        set_skill("literate", 450);
        set_skill("chixin-bianfa", 350);
        set_skill("shuiyue", 320);
        set_skill("wangran-xinfa", 390);
        set_skill("cxwx-quan", 380);
    
        map_skill("force", "wangran-xinfa");
        map_skill("whip", "chixin-bianfa");
        map_skill("dodge", "shuiyue");
        map_skill("unarmed", "cxwx-quan");
        map_skill("parry", "chixin-bianfa");
        map_skill("dodge", "shuiyue");
               
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "whip.mi" :),
        }) );

        setup();
        carry_object("/d/cxwxm/obj/whip.c")->wield();
        carry_object("/d/cxwxm/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        if (!ob->query("yujiao")) {
                command("say ����ȥ����ʦ�ðɣ�");
                return;
        }
        if ((int)ob->query_skill("wangran-xinfa", 1) < 100) {
                command("say ���ŵ��书�����ķ��������������ߣ�"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ������Ȼ�ķ��϶��µ㹦��");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say ��������޳�֮ͽ������ɣ�");
                command("say �����ְ��࣬" + RANK_D->query_respect(ob) +
                        "����ɣ�");
                return;
        }
        if ((int)ob->query("per") < 30) {
                command("say �����书�Ǿ�����ò����ϰ�ã�");
                command("say �㻹��ȥ���ݺ�������!");
                return;
        }
 
        if (ob->query_int() < 50) {
                command("say �����书ȫƾ�������롣");
                command("say Ҫ���޵���߾��磬������Ի�����");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
        }
   if ((string)ob->query("gender")=="Ů��")
   {
                message_vision("�Ϲ���ٻ��ϸ��������Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
                ob->set("yunqian",1);
                       return;}  
   else
      {
                message_vision("�Բ�����ֻ��Ůͽ��\n",ob);
       return;}
        

}
