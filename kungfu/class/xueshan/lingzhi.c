//
// /kungfu/class/xueshan/lingzhi.c  ��������
// by secret
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("��������", ({ "lingzhi shangren", "shangren" }));
        set("long",@LONG
����������ѩɽ���е�λ�ϸߵ����
��һ����ɫ���ģ�ͷ��ɮñ��
LONG
        );
        //set("nickname","����");
        set("title",HIY "������" NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 27);
        set("con", 28);
        set("dex", 26);
        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 20);
        set("combat_exp", 1600000);
        set_skill("mizong-xinfa", 160);
        set_skill("literate", 160);
        set_skill("force", 160);
        set_skill("longxiang", 160);
        set_skill("dodge", 160);
        set_skill("shenkong-xing", 160);
        set_skill("parry", 160);
        set_skill("staff", 160);
        set_skill("xiangmo-chu", 160 );
        set_skill("hammer",160);
        set_skill("riyue-lun",160);
        set_skill("unarmed", 160);
        set_skill("yujiamu-quan", 160);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "yujiamu-quan");
        map_skill("staff", "xiangmo-chu");
        map_skill("hammer", "riyue-lun");
        create_family("ѩɽ��", 4, "������");
        set("class", "bonze");
        setup();
        carry_object("/d/xueshan/obj/c-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

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
        if ((int)ob->query_skill("mizong-xinfa", 1) < 40) {
                command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }
        command("say �ʹ���һЩ�书�ɣ�");
        command("recruit " + ob->query("id"));
        ob->set("title",HIY "����" NOR);
}
