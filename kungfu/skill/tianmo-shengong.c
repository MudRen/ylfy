// tianmo-shengong.c 天魔神功

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
                return notify_fail("你的基本内功火候不足，不能学天魔神功。\n");
        if (lvl > 10 && (int)me->query("shen") > -50000)
                return notify_fail("学天魔神功，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
        skl = this_player()->query_skills();
        sname  = keys(skl);
        for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="tianmo-shengong") continue;
        if (sname[i]=="xixing-dafa") continue;
        if (sname[i]=="yijing-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
            return notify_fail("你不先散了别派内功，怎能学天魔神功？！\n");
    }
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("天魔神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"tianmo-shengong/" + func;
}
