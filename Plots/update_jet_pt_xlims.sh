#!/bin/bash
echo "🔧 Mise à jour des bornes inférieures de xLims (20 → 50) dans les scripts jet_pT_*.py..."

for f in jet_pT_*.py; do
  if grep -q "xLims = (20.0" "$f"; then
    sed -i 's/xLims = (20.0/xLims = (55.0/' "$f"
    echo "✅ $f modifié."
  else
    echo "ℹ️  $f déjà modifié ou ne contient pas xLims = (20.0"
  fi
done

echo "📊 Regénération des figures..."
for f in jet_pT_*.py; do
  python3 "$f"
done

echo "✅ Terminé."
