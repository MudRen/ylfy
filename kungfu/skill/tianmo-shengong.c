// tianmo-shengong.c ��ħ��

inherit FORCE;
inherit F_DBASE;
public string query_type() {
       return "yin";
}
int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	  mapping skl;
      string *sname;
        int i;
		int lvl = (int)me->query_skill("tianmo-shengong", 1);
        int t = 1, j;
        for (j = 1; j < lvl / 10; j++) t*= 2;
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ�����㣬����ѧ��ħ�񹦡�\n");
        if (lvl > 10 && (int)me->query("shen") > -50000)
                return notify_fail("ѧ��ħ�񹦣�Ҫ�ĺ���������������������ò���ѽ��\n");
        skl = this_player()->query_skills();
        sname  = keys(skl);
        for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="tianmo-shengong") continue;
        if (sname[i]=="xixing-dafa") continue;
        if (sname[i]=="yijing-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
            return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ħ�񹦣���\n");
    }
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��ħ��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"tianmo-shengong/" + func;
}
