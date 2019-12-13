//
// /kungfu/class/xueshan/fawang.c  ���ַ���
// by secret
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("���ַ���", ({ "jinlun fawang", "fawang" }));
        set("long",@LONG
����ѩɽ�µĻ��̷�������ѩɽ�µĵ�λ�������������Ħ�ǡ�
��һ���Ϻ����ģ�ͷ��ɮñ��
LONG
        );
        set("title", HIY "����" NOR);
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("str", 60);
        set("int", 60);
        set("con", 60);
        set("dex", 160);
        set("max_qi", 1550000);
        set("max_jing", 1255000);
        set("neili", 4500000);
        set("max_neili", 400000);
        set("jiali", 13100);
        set("combat_exp", 3500000);
		set("xyzx_sys/level", 1500);
		
        set_skill("force", 2320);
        set_skill("longxiang", 1520);
        set_skill("dodge", 2320);
        set_skill("shenkong-xing", 1320);
        set_skill("unarmed", 2320);
        set_skill("yujiamu-quan", 1320);
        set_skill("parry", 2320);
        set_skill("sword", 2320);
        set_skill("mingwang-jian", 1320);
        set_skill("mizong-xinfa", 1320);
        set_skill("literate", 1120);
        set_skill("hammer", 2320);
        set_skill("riyue-lun", 1320 );

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");
        create_family("ѩɽ��", 2, "���̷���");
        set("class", "bonze");
        setup();
        carry_object("/d/xueshan/obj/jinlun")->wield();
        carry_object("/d/xueshan/obj/goldlun")->wield();
        carry_object("/d/xueshan/obj/p-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        add_money("gold",1);
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
        if ((int)ob->query_skill("mizong-xinfa", 1) < 80) {
                command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }
        command("smile");
        command("nod");
        command("say �������ѧϰ�𷨰ɣ�");
        command("recruit " + ob->query("id"));
        ob->set("title", HIY"���"NOR);
}
