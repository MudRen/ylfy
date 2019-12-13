//
// /kungfu/class/xueshan/samu.c  ��ľ���
// by secret
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("��ľ���", ({ "samu huofo", "huofo" }));
        set("long",@LONG
��ľ�����ѩɽ���е��ĸ�ɮ���Է��о�����о���
����һ����ɫ���ģ�ͷ��ɮñ��һ��������˼�����ӡ�
LONG
        );
        set("title", HIY "���" NOR);
        set("gender", "����");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 5500);
        set("max_jing", 5000);
        set("neili", 18000);
        set("max_neili", 9000);
        set("jiali", 200);
        set("combat_exp", 2200000);
        set_skill("mizong-xinfa", 250);
        set_skill("literate", 250);
        set_skill("force", 250);
        set_skill("longxiang", 250);
        set_skill("dodge", 250);
        set_skill("shenkong-xing", 250);
        set_skill("unarmed", 250);
        set_skill("yujiamu-quan", 250);
        set_skill("parry", 250);
        set_skill("sword", 250);
        set_skill("mingwang-jian", 250);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");

        create_family("ѩɽ��", 3, "���");
        set("class", "bonze");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        add_money("silver",5);
}
void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "����") {
                command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }
        if ((string)ob->query("class") != "bonze") {
                command("say �ҷ��ŵ����������ࡣ");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }
        if ((string)ob->query("family/family_name") != "ѩɽ��")        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��µ��ӣ�������ذɣ�");
                return;
        }
        if ((int)ob->query_skill("mizong-xinfa", 1) < 60) {
                command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }
        command("smile");
        command("nod");
        command("say �������ѧϰ�𷨰ɣ�");
        command("recruit " + ob->query("id"));
        ob->set("title", HIY"������"NOR);
}
