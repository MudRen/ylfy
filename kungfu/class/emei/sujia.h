// sujia.h
// create by host jan,8 1998

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 0) {
		command("say �Ҷ������������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ҿ�" + RANK_D->query_respect(ob) +
			"а��̫���ˣ����з����Ƿ����ò�����");
		return;
	}
        command("say �ðɣ����������ˡ�");
	command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");
}