// mylover.c ��ɴ��Ů
// marry 99.8

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��ɴ��Ů", ({ "meng shashaonv", "meng","lover" }));
        set("nickname", MAG "����ʹ" NOR);
        create_family("����������", 3,"����");
        set("jihao",1);
        set("long","�����ǳ��������ŵ������������ʹ����ɴ��Ů��");
        set("gender", "Ů��");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);
        set("dex", 30);
        
        set("max_qi", 50000);
        set("max_jing", 10000);
        set("neili", 150000);
        set("max_neili", 150000);
        set("jiali", 300);
        set("combat_exp", 70000000);
        set("score", 500000);

        set_skill("force", 490);
        set_skill("dodge", 460);
        set_skill("unarmed",400);
        set_skill("parry", 470);
        set_skill("whip", 490);
        set_skill("literate", 600);
        set_skill("chixin-bianfa", 480);
        set_skill("shuiyue", 450);
        set_skill("wangran-xinfa", 500);
        set_skill("cxwx-quan", 410);
   
        map_skill("force", "wangran-xinfa");
        map_skill("whip", "chixin-bianfa");
        map_skill("dodge", "shuiyue");
        map_skill("unarmed", "cxwx-quan");
        map_skill("parry", "chixin-bianfa");
        map_skill("dodge", "shuiyue");
               
        set("chat_chance_combat", 60);
        setup();
        carry_object("/d/cxwxm/obj/whip.c")->wield();
        carry_object("/d/cxwxm/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        if (!ob->query("yunqian")) {
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
 
        if (ob->query_int() < 60) {
                command("say �����书ȫƾ�������롣");
                command("say Ҫ���޵���߾��磬������Ի�����");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
        }
   if ((string)ob->query("gender")=="Ů��")
   {
                message_vision("��ɴ��Ů��ϸ��������Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
                     ob->set("mengsha",1);
                       return;}
   else
      {
                message_vision("�Բ�����ֻ��Ůͽ��\n",ob);
       return;}
        

}

