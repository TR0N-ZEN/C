foreach ($item in $(Get-ChildItem . -Directory))
{
  #Write-Host $item;
  New-Item ".\$item\bin\" -ItemType 'Directory'
}